#ifndef _DASH_DATA_H
#define _DASH_DATA_H

#include <vector>
#include <cstdio>
#include "dirent.h"
#include "json11.h"
using json11::Json;

static const std::string CUR_DIR = ".";
static const std::string PAR_DIR = "..";

struct DashOperation {
	Json descriptor;
	std::string path;
};

struct DashCategory : public DashOperation {
	std::vector<DashOperation> children;
};

struct DashData {
	bool inited;
	std::vector<DashCategory> categories;

	DashData() {
		inited = false;
	}

	DashData(std::string dashPath) {
		printf("dashboard:\n");
		DIR *dir;
		struct dirent *ent;
		if ((dir = opendir(dashPath.c_str())) != NULL) {
			/* print all the files and directories within directory */
			while ((ent = readdir (dir)) != NULL) {
				if((ent->d_type == DT_DIR)
					&& (CUR_DIR != ent->d_name)
					&& (PAR_DIR != ent->d_name)) {
					printf("- %s\n", ent->d_name);
				}
			}
			closedir(dir);
		} else {
			// Could not open directory - inited becomes false for easy retry!
			fprintf(stderr,"Cannot open dashboard at: %s\n", dashPath.c_str());
			inited = false;
		}

		// Mark initialization
		inited = true;
	}
};

#endif /* _DASH_DATA_H */

/* vim: set ts=4 noet : */
