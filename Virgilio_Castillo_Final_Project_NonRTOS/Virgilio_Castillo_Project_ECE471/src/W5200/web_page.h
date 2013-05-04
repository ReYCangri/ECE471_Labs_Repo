/*
 * web_page.h
 *
 *  Created on: Apr 7, 2013
 *      Author: Nate
 */

#ifndef WEB_PAGE_H_
#define WEB_PAGE_H_

const uint8_t website[]= {
		"HTTP/1.0 200 OK\r\n\
		Content-Type: text/html\r\n\r\n\
		<html>\n\
		<head>\n\
		<body>\
		<center><h1>ReYCangri\'s Life Switch!</h1></center>\n\
		<a href=\"yesturnon\">TURN ON</a>\n\
		</body></html>\n"
};

const uint8_t websiteone[]= {
		"HTTP/1.0 200 OK\r\n\
		Content-Type: text/html\r\n\r\n\
		<html>\n\
		<head>\n\
		<body>\
		<center><h1>ReYCangri\'s Life Switch!</h1></center>\n\
		<a href=\"yesturnoff\">TURN OFF</a>\n\
		</body></html>\n"
};




#endif /* WEB_PAGE_H_ */
