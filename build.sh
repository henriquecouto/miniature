rm miniature_client
rm miniature_server

# compile client
gcc miniature_xdr.c client/**.c client/**/**.c -o miniature_client -lm

#compile server
gcc miniature_xdr.c server/**.c server/**/**.c -o miniature_server -lm