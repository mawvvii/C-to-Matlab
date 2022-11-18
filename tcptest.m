clear all 
close all
clc

address = '192.168.178.56';
port = 50907;

server = tcpserver(address,port)
sendata = ["sin", 10];
len = length(sendata);
x = jsonencode(sendata);

waitfor(server,"Connected",1)

disp("going into while")

write(server,x);
disp("sending value")

waitfor(server,"Connected",0)
clear server

