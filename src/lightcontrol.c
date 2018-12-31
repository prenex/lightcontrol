#include "wafer.h"
#include "waferapi.h"
#include <string.h>

static void factor(Request *request, Response *response);
static void index_html(Request *request, Response *response);
static void main_css(Request *request, Response *response);

void server(Request *request, Response *response) {
	printf("%s %s \n", request->method, request->reqStr);
	/* TODO: this becomes a long row of ifs even if one succeeds - some should be maybe put in else clauses for speed if needed. */
	routeRequest(request, response, "", index_html);
	routeRequest(request, response, "/", index_html);
	routeRequest(request, response, "/index.html", index_html);
	routeRequest(request, response, "/main.css", main_css);
	routeRequest(request, response, "/factor", factor);
}

/* index.html */
static void index_html(Request *request, Response *response) {
	/* Serve the file directly */
	/* If the second param would be a filename the browser would download the document */
	serveFile(request, response, "index.html", NULL, "text/html");
}

/* main.css */
static void main_css(Request *request, Response *response) {
	/* Serve the file directly */
	/* If the second param would be a filename the browser would download the document */
	serveFile(request, response, "main.css", NULL, "text/html");
}

static void factor(Request *request, Response *response) {
	char *nStr = QUICK_FORM_TEXT(request, response, "Number to factor:");

	if (nStr != NULL) {
		long n = strtol(nStr, NULL, 10);
		resPrintf(response, "Factors of %li are: ", n);
		long l;
		for (l = 2; l <= n; ++l) {
			if (n % l == 0) {
				resPrintf(response, "%li ", l);
			}
		}
	}
}

/* vim: set ts=4 noet */
