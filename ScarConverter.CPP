#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <mouse_c.h>
#include <key.h>
#include <dos.h>
#include <bitmap.h>

void guide(int N);
void lineB(int x ,int y);
int shownum(int N);
int getdecimalnumber();
int getoctalnumber();
int showBnum(int x,int N);
char* getbinarynum();
void decimaltobinary();
void decimaltooctal();
void decimaltohexa();
void binarytodecimal();
void binarytooctal();
void octaltodecimal();
void octaltobinary();
void octaltohexa();
void binarytoHexa();
void numConvert();
void teaminfo();
void about_us();
void programst();

void main()
{
    int gd=0,gm,errorcode ;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    initmouse();
    showmouse();
    programst();
    getch();
    closegraph();
}

void guide(int N)
{
    setfillstyle(0,0);
    bar(10,160,600,255);
    if(N==1) // choosing the experment
    {
        settextstyle(0,0,1);
        setcolor(3);
        settextstyle(0,0,1);
        outtextxy(10,170,"Decimal to Binary : Tab");
        outtextxy(10,185,"Binary to Decimal : Right");
        outtextxy(10,200,"Decimal to Octal : Home");
        outtextxy(10,215,"Octal to Decimal : Left");
        outtextxy(10,230,"Decimal to Hexadecimal : End");
        outtextxy(10,245,"Binary to Octal : Down");
        outtextxy(300,170,"Octal to Binary : Up");
        outtextxy(300,185,"Octal to Hexa : Delete");
        outtextxy(300,200,"Binary to Hexa : Page_Up");
    }
    else if (N==2) // decimal show
    {
        bar(10,305,300,340);
        outtextxy(10,170,"choose your decimal number you want to convert by change the shown number");
        outtextxy(10,185,"click on - Up - to raise the number");
        outtextxy(10,200,"click on -Down- to reduce the number");
        outtextxy(10,215,"click on -Enter- to input the number");
        setcolor(15);
        settextstyle(0,0,2);
        outtextxy(10,305,"Decimal Input =>");
    }
    else if (N==3) // octal show
    {
        bar(10,305,300,340);
        outtextxy(10,170,"choose your Octal number you want to convert by change the shown number");
        outtextxy(10,185,"click on - Up - to raise the number");
        outtextxy(10,200,"click on -Down- to reduce the number");
        outtextxy(10,215,"click on -Enter- to input the number");
        setcolor(15);
        settextstyle(0,0,2);
        outtextxy(10,305,"Octal Input =>");
    }
    else if (N==4) // binary show
    {
        bar(10,305,300,340);
        outtextxy(10,170,"choose your binary number you want to convert by change the shown number");
        outtextxy(10,185,"click on - Up - to raise the Digit");
        outtextxy(10,200,"click on -Left- to convert the next Digit");
        outtextxy(10,215,"click on -Enter- to input the number");
        setcolor(15);
        settextstyle(0,0,2);
        outtextxy(10,305,"Binary Input =>");
    }
    else if (N==5) // final show
    {
        setcolor(3);
        settextstyle(0,0,1);
        outtextxy(10,170,"click on -Space- to choose another process");
        outtextxy(10,185,"click on -Backspace- to return to the start window");
    }
}

void lineB(int x ,int y)
{
    setcolor(10);
    setlinestyle(0,2,3);
    line(x+3,y,x+18,y);
}

int shownum(int N)
{
    char showN[3];
    setfillstyle(0,0);
    bar(300,300,360,340);
    sprintf(showN,"%d",N);
    setcolor(15);
    settextstyle(0,0,2);
    outtextxy(305,305,showN);
    return 0;
}

int getdecimalnumber()
{
    guide(2);
    int decimal;
    int key;
    decimal = 0;
    shownum(decimal);
    for(;;)
    {
	    key = getkey();
	    switch (key)
	    {
		    case Up : decimal++;shownum(decimal);break;
		    case Down : decimal--;shownum(decimal);break;
		    case Enter: goto S;break;
	    }
	}
    S:
    return decimal;
}

int getoctalnumber()
{
    guide(3);
    int key;
    int d1=0,d2=0,d3=0,d4=0;
    for(;;)
    {
	showBnum(365,d1);
	showBnum(345,d2);
	showBnum(325,d3);
	showBnum(305,d4);
        key = getkey();
        switch(key)
        {
	    case Up :
                if(d1<7)
                    d1++;
                else
                {
                    d1 = 0;
                    if(d2<7)
                        d2++;
                    else
                    {
                        d2 = 0;
                        if(d3<7)
                            d3++;
                        else
                        {
                            d3 = 0;
                            if(d4<7)
                                d4++;
                        }
                    }

                }
                break;
            case Down :
                if(d1>0)
                    d1--;
                else
                {
                    d1 = 7;
                    if(d2>0)
                        d2--;
                    else
                    {
                        d2 = 7;
                        if(d3>0)
                            d3--;
                        else
                        {
                            d3 = 7;
                            if(d4>0)
                                d4--;
                        }
                    }
                }
                break;
	    case Enter : goto S;break;
        }
    }
    S:
    int octalnumber = d1 + d2*10 + d3*100 + d4*1000;
    return octalnumber;
}

int showBnum(int x,int N)
{
    char showN[3];
    setfillstyle(0,0);
    bar(x,300,x+20,320);
    sprintf(showN,"%d",N);
    setcolor(15);
    settextstyle(0,0,2);
    outtextxy(x+5,305,showN);
    return 0;
}

char* getbinarynum()
{
    guide(4);
    int d1,d2,d3,d4,d5,d6,d7,d8,d9,d10;
    d1=d2=d3=d4=d5=d6=d7=d8=d9=d10=0;
    showBnum(525,d1);
    showBnum(500,d2);
    showBnum(475,d3);
    showBnum(450,d4);
    showBnum(425,d5);
    showBnum(400,d6);
    showBnum(375,d7);
    showBnum(350,d8);
    showBnum(325,d9);
    showBnum(300,d10);
    lineB(525,325);
    int key;
    key = getkey();
	switch (key)
    {
	case Up : d1++;showBnum(525,d1);key = getkey();
	case Left : lineB(500,325);
	key = getkey();
	    switch (key)
		{
			case Up : d2++;showBnum(500,d2);key = getkey();
			case Left : lineB(475,325);
		        key = getkey();
			    switch (key)
			    {
			        case Up : d3++;showBnum(475,d3);key = getkey();
				    case Left :lineB(450,325);
			            key = getkey();
				        switch (key)
				        {
				            case Up : d4++;showBnum(450,d4);key = getkey();
				            case Left :lineB(425,325);
				                key = getkey();
					            switch (key)
					            {
		                            case Up : d5++;showBnum(425,d5);key = getkey();
		                            case Left :lineB(400,325);
                                        key = getkey();
	                                    switch (key)
	                                    {
		                                    case Up : d6++;showBnum(400,d6);key = getkey();
		                                    case Left :lineB(375,325);
						                        key = getkey();
							                    switch (key)
							                    {
							                        case Up : d7++;showBnum(375,d7);key = getkey();
							                        case Left :lineB(350,325);
							                            key = getkey();
							                            switch (key)
							                            {
													        case Up : d8++;showBnum(350,d8);key = getkey();
                                                            case Left : lineB(325,325);
                                                                key = getkey();
	                                                            switch (key)
                                                                {
	                                                                case Up : d9++;showBnum(325,d9);key = getkey();
	                                                                case Left : lineB(300,325);
                                                                        key = getkey();
	                                                                    switch (key)
                                                                        {
                                                                            case Up : d10++;showBnum(300,d10);break;
													                        default : goto S;break;
                                                                        }
                                                                        break;
											                        case Enter : goto S;break;
							                                    }
						                                        break;
											                case Enter : goto S;break;
							                            }
						                                break;
										            case Enter : goto S;break;
						                        }
					                            break;
								            case Enter : goto S;break;
					                    }
				                        break;
						            case Enter : goto S;break;
				                }
			                    break;
				            case Enter : goto S;break;
		                }
	                    break;
				    case Enter : goto S;break;
		        }
	            break;
		    case Enter : goto S;break;
	    }
        break;
        case Enter : goto S;break;
    }
    S:
    char binary[10];
    sprintf(binary,"%d%d%d%d%d%d%d%d%d%d",d10,d9,d8,d7,d6,d5,d4,d3,d2,d1);
    return binary;
}

void decimaltobinary()
{
    int decimal = getdecimalnumber();
    char binary[32];
    int index = 0;
    while (decimal > 0)
    {
	    binary[index] = (decimal % 2) + '0';
	    decimal = decimal / 2;
	    index++;
    }
    binary[index] = '\0';
    int length = index;
    for (int i = 0; i < length / 2; i++)
    {
	    char temp = binary[i];
	    binary[i] = binary[length - i - 1];
	    binary[length - i - 1] = temp;
    }
    char output[32];
    sprintf(output, "Binary equivalent: %s", binary);
    settextstyle(0,0,2);
    outtextxy(10, 400, output);
    guide(5);
}

void decimaltooctal()
{
    int decimal = getdecimalnumber();
    char octal[64];
    int index = 0;
    while (decimal > 0)
    {
	octal[index] = (decimal % 8) + '0';
	decimal /= 8;
	index++;
    }
    octal[index] = '\0';
    int length = index;
    for (int i = 0; i < length / 2; i++)
    {
	    char temp = octal[i];
	    octal[i] = octal[length - i - 1];
	    octal[length - i - 1] = temp;
    }
    char output[32];
    sprintf(output, "Octal equivalent: %s", octal);
    settextstyle(0,0,2);
    outtextxy(10, 400, output);
    guide(5);
}

void decimaltohexa()
{
    int decimal = getdecimalnumber();
    char hexa[50];
    int index = 0;
    while (decimal > 0)
    {
	int remainder = decimal % 16;
	char digit;
	if (remainder < 10)
	{
	    digit = remainder + '0';
	}
	else
	{
	    digit = remainder - 10 + 'A';
	}
	hexa[index++] = digit;
	decimal /= 16;
    }
    hexa[index] = '\0';
    int length = index;
    for (int i = 0; i < length / 2; i++)
    {
	    char temp = hexa[i];
	    hexa[i] = hexa[length - i - 1];
	    hexa[length - i - 1] = temp;
    }
    char output[50];
    sprintf(output,"Hexa equivalent: %s", hexa);
    settextstyle(0,0,2);
    outtextxy(10, 400, output);
    guide(5);
}

void binarytodecimal()
{
    char* binary = getbinarynum();
    int decimal = 0;
    for (int i = 0; binary[i] != '\0'; i++)
    {
	    decimal = decimal * 2 + (binary[i] - '0');
    }
    char output[32];
    sprintf(output, "Decimal equivalent: %d", decimal);
    setcolor(15);
    settextstyle(0,0,2);
    outtextxy(10, 400, output);
    guide(5);
}

void octaltodecimal()
{
    int octalnumber = getoctalnumber();
    int decimal = 0;
    int base = 1;
    while (octalnumber > 0) {
        int digit = octalnumber % 10;
        decimal += digit * base;
        base *= 8;
        octalnumber /= 10;
    }
    char output[32];
    sprintf(output, "Decimal equivalent: %d", decimal);
    setcolor(15);
    settextstyle(0,0,2);
    outtextxy(10, 400, output);
    guide(5);
}

void binarytooctal()
{
    char* binary = getbinarynum();
    int decimal = 0;
    for (int i = 0; binary[i] != '\0'; i++)
    {
	    decimal = decimal * 2 + (binary[i] - '0');
    }
    int octal = 0, a = 1;
    while (decimal != 0) {
	octal += (decimal % 8) * a;
	decimal /= 8;
	a *= 10;
    }
    char output[32];
    sprintf(output, "Octal equivalent: %d", octal);
    setcolor(15);
    settextstyle(0,0,2);
    outtextxy(10, 400, output);
    guide(5);
}

void binarytoHexa()
{
    char* binary = getbinarynum();
    int decimal = 0;
    for (int i = 0; binary[i] != '\0'; i++)
    {
	    decimal = decimal * 2 + (binary[i] - '0');
    }
    char hexa[50];
    int index = 0;
    while (decimal > 0) 
    {
        int remainder = decimal % 16;
        char digit;
        if (remainder < 10) 
        {
            digit = remainder + '0';
        }
        else
        {
            digit = remainder - 10 + 'A';
        }
        hexa[index++] = digit;
        decimal /= 16;
    }
    hexa[index] = '\0';
    int length = index;
    for (i = 0; i < length / 2; i++)
    {
	    char temp = hexa[i];
	    hexa[i] = hexa[length - i - 1];
	    hexa[length - i - 1] = temp;
    }
    char output[50];
    sprintf(output,"Hexa equivalent: %s", hexa);
    setcolor(15);
    settextstyle(0,0,2);
    outtextxy(10, 400, output);
    guide(5);
}

void octaltobinary()
{
    int octalnumber = getoctalnumber();
    int decimal = 0;
    int base = 1;
    while (octalnumber > 0) {
        int digit = octalnumber % 10;
        decimal += digit * base;
        base *= 8;
        octalnumber /= 10;
    }
    char binary[32];
    int index = 0;
    while (decimal > 0) 
    {
	    binary[index] = (decimal % 2) + '0';
	    decimal = decimal / 2;
	    index++;
    }
    binary[index] = '\0';
    int length = index;
    for (int i = 0; i < length / 2; i++) 
    {
	    char temp = binary[i];
	    binary[i] = binary[length - i - 1];
	    binary[length - i - 1] = temp;
    }
    char output[32];
    sprintf(output, "Binary equivalent: %s", binary);
    settextstyle(0,0,2);
    outtextxy(10, 400, output);
    guide(5);
}

void octaltohexa()
{
    int octalnumber = getoctalnumber();
    int decimal = 0;
    int base = 1;
    while (octalnumber > 0) {
        int digit = octalnumber % 10;
        decimal += digit * base;
        base *= 8;
        octalnumber /= 10;
    }
    char hexa[50];
    int index = 0;
    while (decimal > 0) 
    {
        int remainder = decimal % 16;
        char digit;
        if (remainder < 10) 
        {
            digit = remainder + '0';
        }
        else
        {
            digit = remainder - 10 + 'A';
        }
        hexa[index++] = digit;
        decimal /= 16;
    }
    hexa[index] = '\0';
    int length = index;
    for (int i = 0; i < length / 2; i++) 
    {
	    char temp = hexa[i];
	    hexa[i] = hexa[length - i - 1];
	    hexa[length - i - 1] = temp;
    }
    char output[50];
    sprintf(output,"Hexa equivalent: %s", hexa);
    settextstyle(0,0,2);
    outtextxy(10, 400, output);
    guide(5);
}

void teaminfo()
{
    int key;
    displaybitmap(0,0,"teamform.bmp");
    setcolor(14);
    setlinestyle(3,2,3);
    rectangle(26,16,150,128);//os
    setcolor(1);
    rectangle(250,16,374,128);//ham
    rectangle(475,16,600,128);//kemo
    setcolor(13);
    rectangle(26,166,150,278);//mz
    rectangle(26,324,150,436);//shq
    rectangle(250,166,374,278);
    rectangle(250,324,374,436);
    rectangle(475,166,600,278);
    rectangle(475,324,600,436);
    setfillstyle(15,0);
    bar(148,26,153,122);
    bar(148,170,153,272);
    bar(148,328,153,430);
    bar(368,26,375,122);
    bar(368,170,375,272);
    bar(368,328,375,430);
    bar(597,26,603,122);
    bar(597,170,603,272);
    bar(597,328,603,430);
    settextstyle(0,1,1);
    setcolor(14);
    outtextxy(153,27,"Team Leader");
    setcolor(13);
    outtextxy(153,174,"Team Member");
    outtextxy(153,332,"Team Member");
    outtextxy(375,174,"Team Member");
    outtextxy(375,332,"Team Member");
    outtextxy(603,174,"Team Member");
    outtextxy(603,332,"Team Member");
    setcolor(1);
    outtextxy(375,27,"Team Member");
    outtextxy(603,27,"Team Member");
    key = getkey();
	switch(key)
	{
	    case Back_Space : cleardevice();about_us();break;
	    default : cleardevice();about_us();break;
	}
}

void about_us()
{
    cleardevice();
    int key;
    displaybitmap(290,30,"Scarcode.bmp");
    displaybitmap(80,30,"AI.bmp");
    displaybitmap(490,30,"kfs.bmp");
    setcolor(14);
    setlinestyle(3,2,3);
    rectangle(287,27,406,150);//Scarcode logo
    rectangle(77,27,205,150); //AI logo
    rectangle(487,27,595,150);//kfs logo
    settextstyle(10,0,1);
    outtextxy(10,160,"hello user, welcome to our application.");
    setcolor(10);
    settextstyle(7,0,1);
    outtextxy(10,220,"this application is used to convert between numerical systems");
    outtextxy(10,250,"and each other.");
    outtextxy(10,280,"It has been made for the practical exam of computer graphics. ");
    outtextxy(10,310,"under the supervaision of Dr.Tamer Medhat.");
    outtextxy(10,340,"Date of exam : 23  / 5 / 2023");
    setcolor(3);
    settextstyle(0,0,1);
    outtextxy(10,400,"All info about our team : click on space key.");
    outtextxy(10,420,"To go back : click on Backspace key.");
    key = getkey();
	switch(key)
	{
	    case Space : cleardevice();teaminfo();break;
	    case Back_Space : cleardevice();programst();break;
	    default : cleardevice();programst();break;
	}
}
void numConvert()
{
    int key;
    cleardevice();
    setcolor(15);
    setlinestyle(0,2,1);
    settextstyle(4,0,5);
    rectangle(170,50,530,140);
    rectangle(167,47,533,143);
    outtextxy(200,65,"Numerical System");
    setcolor(15);
    rectangle(1,155,605,265);
    rectangle(3,157,603,263);
    guide(1);
    setfillstyle(0,0);
    bar(510,240,580,280);
    outtextxy(528,260,"Guide");
    key = getkey();
	switch(key)
	{
	    case Tab : decimaltobinary();break;
	    case Home : decimaltooctal();break;
	    case End : decimaltohexa();break;
	    case Right : binarytodecimal();break;
	    case Left : octaltodecimal();break;
	    case Down : binarytooctal();break;
	    case Up : octaltobinary();break;
	    case Delete : octaltohexa();break;
	    case Page_Up : binarytoHexa();break;
	    default : cleardevice();numConvert();break;
	}
    key = getkey();
	switch(key)
	{
	    case Back_Space : cleardevice();programst();break;
	    case Space : cleardevice();numConvert();break;
	default : cleardevice();numConvert();break;
	}
}

void programst()
{
    int b,x,y;
    cleardevice();
    setcolor(15);
    setlinestyle(0,2,1);
    settextstyle(4,0,5);
    rectangle(170,50,530,140);
    rectangle(167,47,533,143);
    outtextxy(225,65,"Scar Converter");
    settextstyle(4,0,2);
    rectangle(10,439,100,469); // about bottom
    rectangle(8,437,102,471);
    outtextxy(13,441,"About us");
    settextstyle(8,0,1);
    rectangle(246,340,440,376); // exit bottom
    rectangle(244,338,442,378);
    rectangle(246,288,440,322);// NumSystems bottom
    rectangle(244,286,442,324);
    outtextxy(320,342,"Exit");
    outtextxy(250,292,"Numerical systems");
    displaybitmap(528,350,"Scarcode.bmp");
    for(;;)
    {
	getmouse(&b,&x,&y);
	if(b == 1 && x >= 8 && x <= 102 && y >= 437 && y <= 471)
	    about_us();
	else if(b == 1 && x >= 248 && x <= 432 && y >= 338 && y <= 378)
	    exit(1);
	else if(b == 1 && x >= 244 && x <= 442 && y >= 288 && y <= 322)
	    numConvert();
    }
}