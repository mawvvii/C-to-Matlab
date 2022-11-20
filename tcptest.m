clear all 
close all
clc

address = '192.168.178.56';
port = 50907;

server = tcpserver(address,port)

waitfor(server,"Connected",1)
out = sim('tcpsimtest.slx')

disp("going into while")
outv = out.simout
input = jsonencode(outv.signals);
write(server,input);
disp("sending value")

x = read(server,server.NumBytesAvailable,"char")
b = jsondecode(x)
%var.signals.values = b.values
waitfor(server,"Connected",0)
disp("server disconnected")
clear server

