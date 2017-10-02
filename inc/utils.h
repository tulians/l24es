/* l24es - Utils module header */
#ifndef _UTILS_H
#define _UTILS_H

/* Array length from Google's Chromium Project */
#define __arrayLength(x) (int)((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))
#define swap(x,y) do \
   { unsigned char swap_temp[sizeof(x) == sizeof(y) ? (signed)sizeof(x) : -1]; \
     memcpy(swap_temp,&y,sizeof(x)); \
     memcpy(&y,&x,       sizeof(x)); \
     memcpy(&x,swap_temp,sizeof(x)); \
   } while(0)

#endif /* #ifndef _UTILS_H_ */
