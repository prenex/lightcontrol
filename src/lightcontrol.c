#include "wafer.h"
#include "waferapi.h"
#include <string.h>

static void factor(Request *request, Response *response);
static void index_html(Request *request, Response *response);
static void main_css(Request *request, Response *response);
static void video_player_png(Request *request, Response *response);
static void joystick_png(Request *request, Response *response);
static void info_png(Request *request, Response *response);
static void favicon_ico(Request *request, Response *response);
static void game_controller_png(Request *request, Response *response);
static void download_cloud_computing_png(Request *request, Response *response);

void server(Request *request, Response *response) {
	printf("%s %s \n", request->method, request->reqStr);
	/* TODO: this becomes a long row of ifs even if one succeeds - some should be maybe put in else clauses for speed if needed. */
	routeRequest(request, response, "", index_html);
	routeRequest(request, response, "/", index_html);
	routeRequest(request, response, "/index.html", index_html);
	routeRequest(request, response, "/main.css", main_css);
	routeRequest(request, response, "/factor", factor);

	/* Images (I just generate these with vim from ls *.png) */
	routeRequest(request, response, "/video_player.png", video_player_png);
	routeRequest(request, response, "/joystick.png", joystick_png);
	routeRequest(request, response, "/info.png", info_png);
	routeRequest(request, response, "/favicon.ico", favicon_ico);
	routeRequest(request, response, "/game_controller.png", game_controller_png);
	routeRequest(request, response, "/download_cloud_computing.png", download_cloud_computing_png);
}

/* Image files _ generated by vim scripts */
static void video_player_png(Request *request, Response *response) {
	serveFile(request, response, "video_player.png", NULL, "image/png");
}
static void joystick_png(Request *request, Response *response) {
	serveFile(request, response, "joystick.png", NULL, "image/png");
}
static void info_png(Request *request, Response *response) {
	serveFile(request, response, "info.png", NULL, "image/png");
}
static void favicon_ico(Request *request, Response *response) {
	serveFile(request, response, "favicon.ico", NULL, "image/x-icon");
}
static void game_controller_png(Request *request, Response *response) {
	serveFile(request, response, "game_controller.png", NULL, "image/png");
}
static void download_cloud_computing_png(Request *request, Response *response) {
	serveFile(request, response, "download_cloud_computing.png", NULL, "image/png");
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
