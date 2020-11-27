rm miniature_client
rm miniature_server

# compile client
gcc miniature_clnt.c miniature_client.c miniature_xdr.c -o miniature_client -lm

#compile server
gcc miniature_server.c miniature_svc.c miniature_xdr.c server/*.c -o miniature_server -lm