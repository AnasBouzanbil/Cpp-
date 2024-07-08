#include "ft_Post.hpp"


std::string* grab_method(std::string& req)
{  
    
    std::string *ret = new std::string();
    *ret = req.substr(0, req.find(" "));
    return ret;
}

std::string* convert_to_str(size_t len)
{
    std::stringstream ss;
    ss << len;
    std::string *ret = new std::string();
    ss >> *ret;
    return ret;
}

std::string* get_body(t_client_info *client, Directives &working)
{
    std::string filename;
    filename = working.getErrorPages()[client->header.status];
    std::ifstream file;
    file.open(filename.c_str());
    std::string *body = new std::string;
    std::string line;
    while(getline(file, line))
        body->append(line);
    return body;
}

void response(t_client_info* client, std::vector<int> clientSockets, std::vector<Directives> &servers)
{
    (void)servers;
    (void)clientSockets;
    std::string res_total;
    
    std::string *body;
    std::string *cl;
    if (client->header.isError)
    {
        body = get_body(client, client->directive);
        cl = convert_to_str((*body).length());
    }
    else if (client->cgi || client->isSession)
    {
        if (client->cgi)
            body = handle_cgi(client, client->directive, 0);
        else
            body = handle_cgi(client, client->directive, 1);
        cl = convert_to_str((*body).length());
        // client->header.statuscode = "HTTP/1.1 200 Forbidden";
    }
    else
    {
        body = new std::string("");
        cl = new std::string("0");
    }
    // delete client->header.path_p;
    res_total = client->header.statuscode + "\r\n"\
    "Date: Thu, 19 Feb 2009 12:27:04 GMT\r\n" \
    "Server: 0rph1no/1.1\r\n" \
    "Last-Modified: Wed, 18 Jun 2003 16:05:58 GMT\r\n" \
    "ETag: \"56d-9989200-1132c580\"\r\n" \
    "Content-Type: application/x-httpd-php\r\n" \
    "Content-Length: "+*cl+"\r\n" \
    "Accept-Ranges: bytes\r\n" \
    "Connection: close\r\n" \
    "\r\n" \
    + *body;
    const char *res = res_total.c_str();
    send(client->socket, res, strlen(res), 0);
    delete cl;
    delete body;
}

std::string grab_path(std::string& req)
{  
    //GET /HAMID HTTP/1.1
    std::string ret;
    req = req.substr(0, req.find("\r\n"));
    ret = req.substr(req.find(" ")+1, (req.find("HTTP/1.1") - 6));
    return ret;
}
std::string grab_path_dir(std::string& req)
{  
    std::string ret;
    if (req == "/")
        ret = req;
    else
    {
        size_t found = req.rfind("/");
        if (found != std::string::npos && found != 0)
        {
            ret = req.substr(0, req.rfind("/"));
        }
        else
        {
            ret = req;
        }
    }
    return ret;
}

std::string* handle_cgi(t_client_info *client, Directives& working, int flag)
{
    std::string *ret = new std::string();
    std::string filename = client->header.path_p.substr(client->header.path_p.rfind("/"));
    if (flag == 0)
    {
        (void)working;
        int fd[2];
        pid_t pid;
        char *argv[3];
        char *envp[13];
        char buf[1024];
        std::string str;

        pipe(fd);
        pid = fork();
        if (pid == 0)
        {
            filename = "cgi-bin"+filename;
            close(fd[0]);
            dup2(fd[1], 1);
            envp[0] = strdup("REQUEST_METHOD=POST");
            envp[1] = strdup("REDIRECT_STATUS=200");
            envp[2] = strdup("Test=Hamid");
            envp[3] = strdup("File=echo.php");
            argv[0] = strdup("/usr/bin/php");
            argv[1] = strdup(filename.c_str());
            argv[2] = NULL;
            envp[4] = NULL;
            execve("/usr/bin/php", argv, envp);
            exit(0);
        }
        close(fd[1]);
        wait(NULL);
        bzero(buf, sizeof(buf));
        read(fd[0], buf, 1023);
        *ret = buf;
    }
    filename = "sessions"+filename;
    // std::cout << filename.c_str() << std::endl;
    std::ifstream file;
    file.open(filename.c_str());
    if (!file.is_open())
        std::cout << "Error, could not open the file" << std::endl;
    std::string line;
    while(std::getline(file,line))
    {
        *ret+=line;
        *ret+="\r\n";
    }
    return ret;
}

size_t hextodec(const char *s)
{
    std::string str = s;
    int i;
    
    std::istringstream iss(str);
    iss >> std::hex >> i;
    return i;

}
ssize_t get_length(std::string& req)
{

    std::istringstream s;
    s.str(req);
    std::string line;
    while(std::getline(s, line))
    {
        if (line.find("Content-Length") != std::string::npos)
        {
            size_t sep = line.find(":") + 2;
            // printf("{%ld}\n", sep);
            return atoi((line.substr(sep,line.length())).c_str());
        }
    }
    return -1;
}
std::string get_filename(std::string& req)
{
    // std::cout << req.find("filename=")+10 << "-----" << req.find(".mp4") << std::endl;
    int file_index = req.find("filename=");
    std::string temp;
    temp = req.substr(file_index+10, req.find("\"", file_index+10)-file_index-10);
    return temp;
}
std::string generate_filename(std::string& ext)
{
    std::string result;
    char alpha[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',
                          'o', 'p', 'q', 'r', 's', 't', 'u',
                          'v', 'w', 'x', 'y', 'z' };
    for (int i = 0; i<26; i++)
        result = result + alpha[rand() % 26];
    result = result+"."+ext;
    return result;
}
std::string* get_ext(std::string& req)
{
    std::string *ret = new std::string();
    int ctype = req.find("Content-Type:");
    *ret = req.substr(ctype+14, req.find("\r\n",ctype+1)-(ctype+14));
    *ret = (*ret).substr((*ret).find("/")+1);
    return ret;
}

void handle_content_length(t_client_info* client ,std::string& req_body, int binary_data_start)
{
        std::ofstream img;
        const char* data;
        img.open(client->header.filename.c_str(), std::ios::binary | std::ios::app);
        if (img.is_open())
        {

            data = req_body.c_str() + binary_data_start;
            img.write(data, req_body.length() - binary_data_start);
        }
        else
        {
            std::cerr << "Error: Could not open file for writing." << std::endl;
        }
        img.close();
}

void handle_chunked_encoding(t_client_info* client, const std::string& chunked_data) {
    std::ofstream img;
    std::string chunk_size_str;
    size_t chunk_size;
    img.open(client->header.filename.c_str(), std::ios::binary | std::ios::app);
    size_t pos = 0;
    while (pos < chunked_data.length()) {
        size_t chunk_size_end = chunked_data.find("\r\n", pos);
        if (chunk_size_end == std::string::npos)
            break;

        chunk_size_str = chunked_data.substr(pos, chunk_size_end - pos);
        chunk_size = hextodec(chunk_size_str.c_str());
        if (chunk_size == 0)
            break;

        pos = chunk_size_end + 2; // Move past "\r\n"
        if (pos + chunk_size > chunked_data.length())
            break;

        img.write(chunked_data.c_str() + pos, chunk_size);
        pos += chunk_size + 2; // Move past chunk data and "\r\n"
    }

    img.close();
}




int ft_my_Post(t_client_info *client)
{
    size_t start_pos;
    if (client->received)
        client->req_body.append(client->request, client->received);
    if (client->times == 0)
        client->header.fst_line = client->req_body.substr(0, client->req_body.find("\r\n"));
    if (client->req_body.find("Content-Length") != std::string::npos && client->times == 0) {
        if (client->req_body.find("\r\n\r\n") + 5 > (size_t)client->received)
            return 0;
        client->is_content_length = true;
    }
    if (client->is_content_length)
    {
        if (client->times == 0)
        {
            client->bl = get_length(client->req_body);
            if (client->req_body.find("multipart/form-data") != std::string::npos)
            {
                client->binary_data_start = client->req_body.rfind("\r\n\r\n") + 4;
                client->is_multipart = true;
                client->header.filename = get_filename(client->req_body);
            }
            else
            {
                std::string* ext = get_ext(client->req_body);
                client->header.filename = generate_filename(*ext);
                delete ext;
                client->binary_data_start = client->req_body.find("\r\n\r\n") + 4;
            }
        }        // client->req_body.clear();
    }
    if (!client->is_chunked_encoding) {
        if (client->req_body.find("Transfer-Encoding: chunked") != std::string::npos) {
            if (client->req_body.find("\r\n\r\n") + 10 > (size_t)client->received)
                return 0;
            if (client->req_body.find("multipart/form-data") != std::string::npos)
            {
                client->header.filename = get_filename(client->req_body);
                start_pos = client->req_body.rfind("\r\n\r\n") + 4;
            }
            else
            {
                start_pos = client->req_body.find("\r\n\r\n") + 4;
                std::string* ext = get_ext(client->req_body);
                client->header.filename = generate_filename(*ext);
                delete ext;
            }
            client->is_chunked_encoding = true;
            client->req_body = client->req_body.substr(start_pos);
        }
    }
    // std::cout << client->bl << " ------ " << client->req_body << std::endl;
    // client->binary_data_start = 0;
    client->times++;
    if (client->is_chunked_encoding && client->req_body.find("\r\n0\r\n\r\n") != std::string::npos) {
        return 3;
    }
    if (client->is_content_length && client->all_received >= client->bl)
        return 0;
    if (client->is_chunked_encoding)
        return 1;
    if (client->is_content_length)
        return 2;
    return 2;
}

bool is_Req_Err(Locations& loc, t_client_info *client, Directives &working)
{
    std::string temp = client->request;
    std::cout << client->socket << " ---- " << loc.getLocation() << std::endl;
    if (client->times == 0)
    {
        if (loc.getLocation() == "")
        {
            client->times++;
            client->header.isError = true;
            client->header.status = "403";
            client->header.statuscode = "HTTP/1.1 403 Forbidden";
            return true;
        }
        if (loc.getAcceptedMethods()["POST"] == false)
        {
            client->times++;
            client->header.isError = true;
            client->header.status = "405";
            client->header.statuscode = "HTTP/1.1 405 Method Not Allowed";
            return true;
        }
        if (temp.find("Content-Length") != std::string::npos && temp.find("Transfer-Encoding") != std::string::npos)
        {
            client->times++;
            client->header.isError = true;
            client->header.status = "400";
            client->header.statuscode = "HTTP/1.1 400 Bad Request";
            return true;
        }
    }
    if (temp.find("Content-Length") != std::string::npos && client->times == 0)
    {
        int length = get_length(temp);
        if (length > working.getMaxBodySizeInBytes())
        {
            client->times++;
            client->header.isError = true;
            client->header.status = "413";
            client->header.statuscode = "HTTP/1.1 419 Entity Too Big";
            return true;
        }
    }
    else
    {
        if (client->all_received > (size_t)working.getMaxBodySizeInBytes())
        {
            std::cout << client->all_received << " ----- "<< (size_t)working.getMaxBodySizeInBytes() << std::endl;
            client->times++;
            client->header.isError = true;
            client->header.status = "413";
            client->header.statuscode = "HTTP/1.1 413 Entity Too Big";
            return true;
        }
    }
    return false;
}

int handle_Post(std::vector<int> &clientSockets, std::vector<Directives> &servers, t_client_info *client)
{
    (void)clientSockets;
    if (client->times == 0)
    {
        std::string temp = client->request;
        client->header.file_path = grab_path(temp);
        client->header.path_dir = grab_path_dir(client->header.file_path);
        client->header.path_p = grab_path(temp);
        if (client->header.path_dir == "/sessions")
            client->isSession = true;
        // for (size_t i = 0; i < clientSockets.size(); i++)
        // {
        //     if (clientSockets[i] == client->socket)
        //     {
        //         std::cout << servers[i].getRoot() << " ---- " << i<<  std::endl;
        //         client->directive = servers[i];
        //         break;
        //     }
        // }
        client->directive = servers[client->serverIndex];
        // std::cout << "afin" << std::endl;
        // std::cout << client->directive.getListen() << std::endl;
        std::vector<Locations> locations = client->directive.getLocationsVec();
        for (size_t i = 0; i < locations.size(); i++)
        {
            // std::cout << "hamid" << std::endl;
            if (client->header.path_dir == locations[i].getLocation())
            {
                // std::cout << client->header.path_dir << std::endl;
                client->working_location = locations[i];
                break;
            }
        }
    }
        if (client->working_location.getCgi()[".php"] != "")
        {
            client->cgi = true;
        }
        int ret;
        if (is_Req_Err(client->working_location, client, client->directive))
            return 3;
        ret = ft_my_Post(client);
	    if (ret == 3)
        {
		    handle_chunked_encoding(client, client->req_body);
            client->header.isError = false;
            client->header.status = "200";
            client->header.statuscode = "HTTP/1.1 200 OK";
            return 0;
        }
        if (ret == 0)
        {
            handle_content_length(client, client->req_body,client->binary_data_start);
            client->header.isError = false;
            client->header.status = "200";
            client->header.statuscode = "HTTP/1.1 200 OK";
            return 1;
        }
    return 2;
}

Request::~Request()
{
}