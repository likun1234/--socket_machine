#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <vector>
#include <cstring>
using namespace std;
#define PORT 3001
std::string transform_angle(std::vector<double> a)
{
	std::string out;
	std::vector<std::string> temp;
	//a[2] += 66.0;

	for (auto iter = a.begin(); iter != a.end(); iter++) {
		char p[255];
		memset(p, 0, 255);
		sprintf(p, "%.2f", *iter);
		std::string str(p);
		std::cout<<str<<std::endl;
		temp.push_back(str);
	}
	out = "(" + temp[0] + "," + temp[1] + "," + temp[2] + "," + temp[3] + "," + temp[4] + "," + temp[5] + "," + temp[6] + "," + temp[7] + "," + temp[8] + "," + temp[9] + "," + temp[10] + "," + temp[11] + "," + temp[12] + ")";
	return out;
}



void transform_1(std::string sf, char ca[])
{
    for(size_t i=0;i<sf.length();i++)
    {
        ca[i]=sf[i];
    }
}



int
main(int argc, char** argv)
{
	struct sockaddr_in s_in;//server address structure(服务器地址结构)
	struct sockaddr_in c_in;//client address structure(客户端地址结构)1
	int l_fd,c_fd;
	socklen_t len;
	char buf[1];//content buff area(内容缓冲区)
	// string tem;
	memset((void *)&s_in,0,sizeof(s_in));

	s_in.sin_family = AF_INET;//IPV4 communication domain(通信领域)0.78,-0.02,0.62,-0.09
	s_in.sin_addr.s_addr = INADDR_ANY;//accept any address(接受任何地址)
	s_in.sin_port = htons(PORT);//change port to netchar (改变端口 netchar)

	l_fd = socket(AF_INET,SOCK_STREAM,0);//socket(int domain, int type, int protocol)
	bind(l_fd,(struct sockaddr *)&s_in,sizeof(s_in));
	listen(l_fd, 1);
	std::cout<<"-------------------begin---------------------"<<std::endl;

	c_fd = accept(l_fd,(struct sockaddr *)&c_in,&len);
	std::cout<<"-------------------link----------------------"<<std::endl;
	while(1)
	{
  
                cout<<"301,700,-10,600,-157,-19,-15"<<endl;
                string pos;
		cin>>pos;
		char str[pos.length()];
		transform_1(pos, str);
                cout<<pos<<endl; 
                int str_len = strlen(str);//sizeof(str)/sizeof(str[0])-1;
		write(c_fd,str,str_len);
		read(c_fd, buf, 1);//read the message send by client    a
                write(c_fd, "b", 1);
		cout<<"buf 1 is : "<<buf<<endl;
	}
}

