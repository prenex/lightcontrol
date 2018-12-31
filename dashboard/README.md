Dashboard configuration
=======================

How it works
------------

This directory tree is basically simple the "database" or "coniguration" of the dashboard screen and the operators of lightcontrol. This part is completely user-defined and very easily extensible in order to make you run your home-control scripts or control your TV that becomes "smart" by the orange pi that runs this software on it to play youtube videos or whatever.

Details / scripting
-------------------

So you configure this simple webapp by creating a directory structure with your scripts. There is nothing better than explaining by a proper example so here it comes an example as the full explanation of main configuration features.

Lets see the following directory structure (set up for a home entertainment Pi behind a TV):


```
img/
	video.png
	cloudl.png
	joytick.png
	...
dashboard/
	Video/
		PlayMPV/
			icon.png
			desc.json
			run.sh
		StopMPV/
			desc.json
			run.sh
		GotoSecMPV/
			desc.json
			run.sh
	Torrent/
		...
	...
	Information/
		desc.json
		run.sh
```

This leads to the following:

* This setup will lead to have as many buttons on the main dashboard as there are subdirectories below the dashboard directory.

* They will use names and icons as describen in desc.json in them.

* If the name is not defined in desc.json it defaults to the directory name.

* If the icon is not defined in the desc.json it is the default one. The default is icon.png from the same directory (see PlayMPV) or the system-wide default operation icon (for example a gear or some such thing). This way a "component" can be a completely self-contained directory tree with all its things and a makefile for installing necessary software or stuff if needed! This enables creating and sharing 3rd party "components" that others might enjoy too. This way it is nearly like a package manager - just more simple haha.

* Scripts can have parameters which are also described in desc.json (by default there is no param and they are just buttons).

* If there is no subdirectory for the operations of the category, just its run.sh will be ran (so always leaf nodes are ran - see info above).

* In desc.json we can tell the system that we should present stdout of the run.sh

* The desc.json can also contain links to be redirected to after the script operations (for other webabbs for example).

* Top-level directories are shown as only button tiles in three colums - while other levels have full functionality but only full rows/op.

Some examples are provided with if you clone the repo which are basically my own stuff that runs on my orange pi behind my brothers TV.

Technically the desc.json is what is sent back to the javascript client side with AJAX when it updates the screen.

TODO: A complete desc.json example should be here!
