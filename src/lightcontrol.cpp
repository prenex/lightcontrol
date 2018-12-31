extern "C" { /* These are originally for C usage */
	#include "wafer.h"
	#include "waferapi.h"
}

#include <cstring>
#include "json11.h"
using json11::Json;

/* Pages */
static void index_html(Request *request, Response *response);
static void main_css(Request *request, Response *response);
/* REST services */
static void REST_categories(Request *request, Response *response);
/* Images */
static void video_player_png(Request *request, Response *response);
static void joystick_png(Request *request, Response *response);
static void info_png(Request *request, Response *response);
static void favicon_ico(Request *request, Response *response);
static void game_controller_png(Request *request, Response *response);
static void download_cloud_computing_png(Request *request, Response *response);

/* TODO: this becomes a long row of ifs even if one succeeds - some should be maybe put in else clauses for speed if needed. */
void server(Request *request, Response *response) {
	printf("%s %s \n", request->method, request->reqStr);

	/* Rem.: ifs are here to make the runtime faster a bit */
	/* Pages */
	if(!routeRequest(request, response, "/", index_html)) {
	if(!routeRequest(request, response, "/index.html", index_html)) {
	if(!routeRequest(request, response, "/main.css", main_css)) {
	if(!routeRequest(request, response, "/favicon.ico", favicon_ico)) {

	/* REST services */
	routeRequest(request, response, "/REST_categories", REST_categories);

	/* Images (I just generate these with vim from ls *.png) */
	// TODO: maybe do some generic handler for cases when the file has *.png in it!
	routeRequest(request, response, "/video_player.png", video_player_png);
	routeRequest(request, response, "/joystick.png", joystick_png);
	routeRequest(request, response, "/info.png", info_png);
	routeRequest(request, response, "/game_controller.png", game_controller_png);
	routeRequest(request, response, "/download_cloud_computing.png", download_cloud_computing_png);
	routeRequest(request, response, "", index_html);
	}}}}
}

/* Image files _ generated by vim scripts */
/* -------------------------------------- */

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

/* Pages */
/* ----- */

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

/* REST services */
/* ------------- */

static void REST_categories(Request *request, Response *response) {
	Json my_json = Json::object {
		{ "key1", "value1" },
		{ "key2", false },
		{ "key3", Json::array { 1, 2, 3 } },
	};
	std::string json_str = my_json.dump();

	resPrintf(response, "%s\n", my_json.dump().c_str());
}

/* vim: set ts=4 noet */
