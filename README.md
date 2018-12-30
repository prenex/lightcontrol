
# What is lightcontrol

A really lightweight web application using WAFer (see later) for showing a simple dynamic "menu" as a tree of control operations. Originally made to control scripts and stuff for the orange pi that lays behind my bro's half-smart-TV to let non-linux users quickly start/stop a youtube video and such.

Things are really lightweight and simple - unnecessary functionality is just not here...

# WAFer info

WAFer is a C language-based ultra-light scalable server-side web applications framework. Think node.js for C programmers. Because it's written in C for the C eco system, WAFer is wafer-thins with a memory footprint that is only a fraction of that of node.js and other bulky frameworks.

We only made a copy of server.c (as lightcontrol.c), put our code inside the function `void server(Request request)` in `lightcontrol.c` and, make with `make SERVER=lightcontrol`, and we are good to go.

WAFer can operate in many different configurations, all selected at compile time. They include:


1. Single-threaded (Default) or multi-threaded (make with `THREADS=n` where n>0)

2. Select(Default) or epoll (make with `LOOP=epoll`) based event loop

3. C10K mode (make with `LOOP=epoll MAX_CON_CONS=n` where n>10,000)


Default port is 4242. Set environment variable 'PORT' to change it.

That's really it.

### Acknowledgements

1. [WAFer](https://github.com/riolet/WAFer) which serves as the base of the whole web application presented here.

1. [J. David Blackstone](http://sourceforge.net/u/jdavidb/profile/) and [Feng Shen](https://github.com/shenfeng), whose web servers have been repurposed to build this platform.

2. [Mark Karpeles](https://github.com/MagicalTux) for the incredible number of bug fixes!

3. [Fine folks at /r/programming](http://www.reddit.com/r/programming/) for the honest and constructive feedback.

