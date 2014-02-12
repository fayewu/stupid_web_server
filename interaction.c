#include "socket.h"
#include "interaction.h"

static struct SWS_request_t {
	int method;	
	char *url;
	int version;
}; 

void
SWS_connect_init(struct SWS_request_t **request)
{
	struct SWS_request_t *req = *request;

	request = (struct SWS_request_t *)SWS_mmalloc(struct SWS_request_t);
}

void
SWS_web_interation(int connect_fd)
{
	int n;
	char recvline[SWS_request_header] = {0}; 
	struct SWS_request_t **request;

	SWS_connect_init(requst);

	/* deal with http requst header */
	/* TODO 超时*/
	if ((n = SWS_read_request_line(connect_fd, recvline, 
				SWS_read_request_line)) >= 0) {
		if (n == 0) {
			SWS_log_info("[%s:%d] client terminated prematurely",
					__FILE__, __LINE__);		
			exit(EXIT_SUCCESS);
		}
		
		SWS_parse_request_header_line(recvline, request);
	}
} 		

int
SWS_parse_request_header_line(const char *header, struct SWS_request_t **request)
{
	struct SWS_request_t *req = *request;	

	sprintf(header, "%s %s %s\r\n", req->method, req->url, req->version);

	if (!strcmp(req->method, "GET"))
}
