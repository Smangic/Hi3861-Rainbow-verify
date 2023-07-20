#include"Compose2.h"
#include"GFpow2.h"

int shortMessageSigned(unsigned char *m,const unsigned char *sm,const unsigned char *pk,const int ovn1,const int nv1,const int ovn){
    
    //print_byte_stream(m, nv1);

    int i,j,k, eof = 0;
    int ij = 0;
    GFpow temp, x[ovn1], temp2, temp3,pk_ij;

    for (k = 0; k < ovn; k++){
        x[k] = GFpow_init_with_value(sm[k]);
        //printf("x[%d] is %d\n",k,GFpow_to_char(&x[k]));
    }
    x[ovn] = GFpow_init_with_value(1);
    //printf("x[%d] is %d\n",ovn,GFpow_to_char(&x[ovn]));

    for (k = 0; k <nv1; k++){

        temp = GFpow_init_with_value(0);

        for (i = 0; i < ovn1; i++) {
            for (j = i; j < ovn1; j++) {
                GFpow_mul(&x[i], &x[j], &temp2);
                pk_ij = GFpow_init_with_value(pk[ij++]);
                GFpow_mul(&temp2, &pk_ij, &temp3);
                GFpow_add_equal(&temp, &temp3);
                //printf("temp is %d\n",GFpow_to_char(&temp));
            }
        }

        if (m[k] != GFpow_to_char(&temp)) {
            eof = -100;
            //m[k] = GFpow_to_char(&temp);
            break;
        }
    }

    return eof;
}
