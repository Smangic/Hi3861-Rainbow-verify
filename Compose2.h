#ifndef COMPOSE2_H
#define COMPOSE2_H

#include <stdio.h>


// int keypair(unsigned char *sk, unsigned long *sklen,
//             unsigned char *pk, unsigned long *pklen);

int shortMessageSigned(unsigned char *m,const unsigned char *sm,const unsigned char *pk,const int ovn,const int nv1, const int ovn1);

// int signedShortMessage(unsigned char *sm, unsigned long *smlen,
//                        const unsigned char *m, const unsigned char *sk,const int nv1, const int ovn, const int ovn1);

#endif // COMPOSE_H