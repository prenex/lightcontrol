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
dashboard/
	Video/
		icon.png
		PlayMPV/
			icon.png
			run_s.sh
		StopMPV/
			icon.png
			run.sh
		GotoSecMPV/
			icon.png
			run_i.sh
	Torrent/
		icon.png
		...
	...
	Information/
		icon.png
		run.sh
```

This leads to the following:

* This setup will lead to have as many buttons on the main dashboard as there are subdirectories below the dashboard directory.

* They will use names as their directory name is, and icons as the icon.png in them (or a default icon if there is no file).

* Parameter types and numbers are "encoded" in the script name for simplicity.

* If there is no subdirectory for the operations of the category, its run.sh will be ran.

* In any case a run.sh returns a string, we will get redirected to that page and the server will try to serve that file directly.

