# C-to-Matlab
sending variables from C++ to Matlab

matlab code : 

first run : 
server = tcpserver("192.168.178.56",58975);
then run c++ file 
add a blocker 
then write 
data = read(server,server.NumBytesAvailable,"char");


The original microsoft code:
https://learn.microsoft.com/en-us/windows/win32/winsock/complete-server-code
Not sure if it has anything to do with this but add a rule in your firewall
https://otree.readthedocs.io/en/latest/server/adhoc.html
