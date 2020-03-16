_SHORT STOREE_
Mikey only works on Mac Mavericks

—LINUX_
If you wanna try compiling for linux, it needs openGL 3.0 or greater,
so I couldn’t compile on my linux netbooks.
Also, you will need to insert the glewInit() stuff for that,
and compile with a static glew library too…

-WYNDHAM_
Didn’t try windows because I can’t get SDL to static link to a lib..
don’t wanna put a dll in every package.. 
also lua wouldn’t static link so i’d have to do a lua src branch here..

BUT THEORETICALLY SDL AND LUA SHOULD BE CROSS PLAT!
ITS MOSTLY ABOUT GATES’ CL DOS STRUCTURE
and
OPENGL 3.0 NEEDS TO BE EVERYWHERE WITH THE VAOS AND VBOS etc.