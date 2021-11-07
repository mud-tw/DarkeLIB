# DarkeLIB
The original DarkeLIB as used by Daybreak Ridge from 1999. i made some edits in 2005 wuth schroom and hellbringer.

thrace and i hosted darkelib as daybreak ridge in 1998 with traer. i got the darkelib from drizzt and zortek with permission.

## How to use

* Download and install docker
  * set docker to linux mode if you're on windows
* Clone or download this repo into a folder
* execute `docker-compose up`
* if you don't have docker-compose then:
  * `docker build -t darkelib:latest .`
  * windows: `docker run --rmi -p 7878:7878 -p 7879:7879 -v %CD%:/home/parnell/mud darkelib`

Log in as parnell `P@ssw0rd123` to be admin

Read `mudlib/doc/mudlib/Start`.

## Develop

command notes:
```bash
# reload object and its inherits
massup -R
# check inherits
eval string *i = deep_inherit_list(find_player("zmax")); int m = sizeof(i); while(m>0) { write(i[m-1]); m--; }
eval string *i = deep_inherit_list(present("dhamon", environment(find_player("zmax")))); int m = sizeof(i); while(m>0) { write(i[m-1]); m--; }
```

## modernizing DarkeLIB
