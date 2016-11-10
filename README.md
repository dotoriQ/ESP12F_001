#ESP0001_LM35DZ_thingSpeak project comment..

1. myprivate.h is not exists & gitignored
2. you can make myprivate.h like as
````cpp
#ifndef MYPRIVATE_H_
#define MYPRIVATE_H_
    
#define MY_APIKEY	"your_ThingSpeak_API_key"
#define MY_AP 		"your_AP"
#define MY_AP_PWD 	"your_Ap_Password"

#endif
````  
    
