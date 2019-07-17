#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <pacemaker.h>

/* Globals */
int timer=0;
int sena = 0;
int senv = 0;
int pula = 0;
int pulv = 0;
int avd = 150;
int avdelay = -1;
int lastpulse = 0;
int lastpacedpulsea = 0;
int lastsenseda = 0;
int lastpacedpulsev =0;
int lastsensedv = 0;
int maxtime = 1000;
int mintime = 500;
int nr = 830;
int sensortime = 500;
int incrementtime = 50;
int responsefactor = 5;
int hysteresistime = 1000;
int hysteresis = 0;
int vrp =320;
int arp =250;
int pvarp = 250;
int schd = 1;
enum behave {nondet,dead,missv};
enum m {VOO, AOO, VVI, AAI, VVT, AAT, DOO, DDI,DDD,VDD,AOOR,AAIR,VOOR,VVIR,VDDR,DOOR,DDIR,DDDR,all};
enum activity {low,med,high};

/* Generated by Control Refinement */

void updatetimers()
{
if (timer>=0) 
timer = timer+50;
if (avdelay == -1  && lastpulse >0)
{
timer = 0;
avdelay=-1;
lastpulse=0;
}
if(lastpacedpulsev >0 && lastpulse >0)
{
timer =0;
avdelay=-1;
lastpacedpulsev=0;
lastpulse=0;
}
if(lastpacedpulsev >0)
{
avdelay=-1;
lastpacedpulsev=0;
}
if(lastpacedpulsea >0)
{
avdelay=0;
lastpacedpulsea=0;
}
if(avdelay>=0)
avdelay = avdelay+50;
}

void environment(enum behave b)
{
if(b == nondet) 
{
/* Normal Non Deterministic Heart */
if((timer - lastpulse) >= nr)
{
pula=1;
lastpulse = timer;avdelay=0;
}

if( avdelay >= avd)
{
pulv=1;
avdelay=-1;
}

}
if(b == missv)
{
/* Missing Ventricle Pulse Heart */
if((timer - lastpulse) >= nr)
{
pula = 1;
lastpulse = timer;
avdelay=0;
}

if(avdelay >= avd)
{
/*::pulsev!1;avdelay=-1;*/
timer =0;
avdelay=-1;
}
}

if(b == dead)
{
/* Dead Heart */

if((timer - lastpulse) >= nr)
{
/*::pulsea!1;lastpulse = timer;avdelay=0;*/
timer=0;
lastpulse = timer;
avdelay=0;
}

if(avdelay >= avd)
{
/*::pulsev!1;avdelay=-1;*/
timer =0;
avdelay=-1;
}
}
}

void sensor()
{

if(pula ==1 && sena ==1)
{
sena=0; 
pula=0;
}

if(pula ==1) 
{ 
sena = 1;
pula =0;
lastsenseda = timer;
}
else 
{
sena = 0;
lastsenseda = 0;
}

if(pulv ==1 && senv ==1) 
{ 
senv=0; 
pulv=0;
}

if(pulv==1) 
{
senv =1;
pulv=0;
lastsensedv = timer;
}
else 
{ 
senv =0;
lastsensedv = 0;
}

}

void pacegen(enum m mode)
{

if(mode == VOO || mode == DOO || mode == DDD|| mode == VDD || mode == VOOR || mode == DOOR || mode == DDDR || mode == VDDR)
{

if((timer - lastpacedpulsev) > mintime && (timer - lastpacedpulsev) < maxtime )

if(mode == VOOR || mode == DOOR || mode == DDDR || mode == VDDR) 
{

if((timer - lastpacedpulsev) >= (sensortime + responsefactor*incrementtime)) 
{
pulv =1;
lastpacedpulsev = timer;
avdelay=-1;
}
}
else 
{ 
pulv = 1;
lastpacedpulsev = timer;
avdelay=-1; 
}
}

if(mode == AOO || mode == DOO || mode == DDD || mode == AOOR || mode == DOOR || mode == DDDR)
{

if((timer - lastpacedpulsea) > mintime && (timer - lastpacedpulsea) < maxtime )

if(mode ==AOOR ||mode == DOOR || mode == DDDR)  
{

if((timer - lastpacedpulsea) >= (sensortime + responsefactor*incrementtime))
{
pula =1;
lastpacedpulsea = timer;
avdelay=0;
}
}
else 
{
pula =1;
lastpacedpulsea = timer;
avdelay=0;
}
}

if(mode == VVI || mode == DDI || mode == VVIR || mode == DDIR )
{

if(senv == 1 && timer - lastpacedpulsev > vrp) 
{
lastpacedpulsev = timer; 
avdelay = -1;
}

if(hysteresis == 1) 
responsefactor = 10;

if((timer - lastpacedpulsev) > mintime && (timer - lastpacedpulsev) < maxtime )

if(mode == VVIR || mode == DDIR )
{

if((timer - lastpacedpulsev) >= (sensortime + responsefactor*incrementtime)) 
{
pulv =1;
lastpacedpulsev = timer;
avdelay=-1;
}
}
else 
{
pulv = 1;
lastpacedpulsev = timer;
avdelay=-1;
}
}

if(mode == AAI || mode == DDI || mode == AAIR ||mode == DDIR)
{

if(sena ==1 && timer - lastpacedpulsea > arp) 
{
lastpacedpulsea = timer;
avdelay=0;
}

if(hysteresis == 1) 
responsefactor = 10;

if((timer - lastpacedpulsea) > mintime && (timer - lastpacedpulsea) < maxtime )

if(mode == AAIR ||mode == DDIR)
{

if ((timer - lastpacedpulsea) >= (sensortime + responsefactor*incrementtime)) 
{
pula =1;
lastpacedpulsea = timer;
avdelay=0;
}
}
else 
{
pula=1;
lastpacedpulsea = timer;
avdelay=0;
}
}

if(mode == VVT && timer - lastpacedpulsev > vrp)
{

if(senv==1) 
{ 
pulv=1;
lastpacedpulsev = timer;
avdelay=-1;
}

if((timer - lastpacedpulsev) > mintime && (timer - lastpacedpulsev) < maxtime )
{
pulv=1;
lastpacedpulsev = timer;
avdelay=-1;
}
}

if(mode == AAT && timer - lastpacedpulsea > arp)
{

if (sena == 1) 
{
pula = 1;
lastpacedpulsea = timer;
avdelay=0;
}

if((timer - lastpacedpulsea) > mintime && (timer - lastpacedpulsea) < maxtime )
{
pula=1;
lastpacedpulsea = timer;
avdelay=0;
}
}

if(mode == DDD || mode == VDD ||mode ==VDDR ||mode == DDDR)
{

if(sena == 1 && timer - lastpacedpulsev > pvarp) 
avdelay=0;

if(hysteresis == 1)  
responsefactor = 10;

if(senv == 1 && timer - lastpacedpulsev > pvarp)  
avdelay=-1;
}

if(mode == DOO || mode == DDI || mode ==VDD || mode == DDD ||mode ==DOOR || mode == DDIR || mode == VDDR ||mode ==DDDR)
{

if(avdelay >= avd) 
{
pulv =1;
lastpacedpulsev = timer;
avdelay=-1;
}
}

}

void accelerometer(enum activity act)
{

if(act == low)
{

if(responsefactor > 3) 
responsefactor = 3;

if(responsefactor == 3)  
responsefactor = 2;

if(responsefactor == 2) 
responsefactor = 1;
}

if(act == med)
{

if(responsefactor > 6)  
responsefactor =  6;

if(responsefactor == 6)  
responsefactor = 5;

if(responsefactor <= 5)  
responsefactor = 4;
}

if(act == high)
{

if(responsefactor < 7)  
responsefactor = 7;

if(responsefactor == 7)  
responsefactor = 8;

if(responsefactor == 8) 
responsefactor = 9;
}

}

void main()
{
enum behave b = nondet;
enum m mode = DDD;
enum activity act = low;
int hysteresis = 1;

while(1)
{
updatetimers();
environment(b);
sensor();
accelerometer(act);
pacegen(mode);
}
}
