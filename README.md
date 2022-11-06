# C-to-Matlab
sending variables from C++ to Matlab

matlab code : 

first run : 
server = tcpserver("192.168.178.56",58975);
then run c++ file 
add a blocker 
then write 
data = read(server,server.NumBytesAvailable,"char");
