
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
void rotate();

typedef float point[2];
point vbase[]={{395.0,70.0},{315.0,70.0},{355.0,20.0}};//fire for 1st bock
point vbase2[]={{330,200},{355,130},{380,200}};//fire for 2nd iddle block
point vnoz2[]={{405,185},{375,185},{390,155}};//fire for left and
point vnoz3[]={{305,185},{335,185},{320,155}};//right pieces
point vbase3[]={{330,320},{380,320},{355,250}};//fire for 3rd block
int n=4;

typedef float rect[3];

rect head1[]={{330,400},{380,400},{365,450},{345,450}};
rect head2[]={{345,450},{365,450},{365,460},{345,460}};
rect head3[]={{345,460},{365,460},{355,470}};
rect topcyl1[]={{330,320},{380,320},{380,400},{330,400}};
rect midcyl1[]={{330,200},{380,200},{380,320},{330,320}};
rect botcyl1[]={{330,100},{380,100},{380,200},{330,200}};
rect noz1[]={{330,100},{380,100},{395,70},{315,70}};

rect body1[]={{380,310},{400,310},{400,200},{380,200}};
rect head4[]={{380,310},{400,310},{395,320},{385,320}};
rect head5[]={{385,320},{395,320},{395,325},{385,325}};
rect head6[]={{385,325},{395,325},{390,330}};
rect noz2[]={{380,200},{400,200},{405,185},{375,185}}; 
rect body2[]={{330,310},{310,310},{310,200},{330,200}};
rect head7[]={{330,310},{310,310},{315,320},{325,320}};
rect head8[]={{325,320},{315,320},{315,325},{325,325}};
rect head9[]={{325,325},{315,325},{320,330}};
rect noz3[]={{330,200},{310,200},{305,185},{335,185}};

rect sky[]={{0,1000},{0,170},{1000,170},{1000,1000}};
rect sky_col[]={{1,1,1},{0,0,.5},{1,1,1},{0,0,.5}};
rect sky1[]={{0,700},{0,1500},{1000,1500},{1000,700}};
rect sky_col1[]={{0.4,0.4,0.4},{0,0,.4},{0.4,0.4,0.4},{0,0,.4}};
rect sky2[]={{0,1500},{0,2000},{1000,2000},{1000,1500}};
rect sky_col2[]={{0.2,0.2,0.2},{0,0,.3},{0.2,0.2,0.2},{0,0,.3}};
rect sky3[]={{0,2000},{0,2500},{1000,2500},{1000,2000}};
rect sky_col3[]={{0.0,0.0,0.0},{0,0,.2},{0.0,0.0,0.0},{0,0,.2}};
rect ground[]={{0,0},{0,170},{1000,170},{1000,0}};
rect grass[]={{0,170},{50,220},{100,170},{150,260},{200,170},{250,220},{300,170},{350,260},{400,170},{450,220},{500,170},{550,260},{600,170},{650,220},{700,170},{750,270},{800,170},{850,230},{900,170},{950,270},{1000,170}};
rect whitesurf1[]={{220,0},{240,150},{460,150},{500,0}};
rect redbox[]={{240,20},{260,130},{440,130},{480,20}};
rect whitesurf2[]={{260,40},{280,110},{420,110},{460,40}};
rect sup_base[]={{535,60},{537,80},{595,80},{597,60}};
rect sup_net[]={{550,70},{580,100},{550,130},{580,160},{550,190},{580,220},{550,250},{580,280},{550,310},{580,340},{550,370},{580,400},{550,430},{580,450},{550,450},{580,430},{550,400},{580,370},{550,340},{580,310},{550,280},{580,250},{550,220},{580,190},{550,160},{580,130},{550,100},{580,70}};
rect left_rod[]={{550,70},{540,70},{540,450},{550,450}};
rect right_rod[]={{580,70},{580,450},{590,450},{590,70}};
rect sup_top[]={{540,450},{540,460},{565,470},{590,460},{590,450}};
rect hold_pi[]={{365,450},{365,460},{540,460},{540,450}};

rect stars[]={{100,450},{200,550},{100,650},{200,450},{100,550},{500,450},{600,550},{500,650},{600,450},{500,550},{250,600},{550,600},{150,500},{450,600}};
unsigned char k='\0';
float x,y,xc=600,yc=500,r=100,t=0,h,l,r1=140,t1=90;
void drawstring(float x,float y,char *s)
{
	glRasterPos2f(x,y);
	for(int i=0;s[i]!='\0';i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[i]);
		glFlush();
}

void mykeys(unsigned char key,int x,int y)
{
	k=key;
}

/*-----function for stars movement-----*/
void starsfunc()
{
	glBegin(GL_POINTS);
	for(int i=0;i<=13;i++)
	{
		glColor3f(1,1,1);
		stars[i][1]=stars[i][1]-15;
		glVertex2fv(stars[i]);
		if(stars[i][1]==0)
			stars[i][1]=450;
	}
	glEnd();
}

/*-----function to display planet-----*/
void planet()
{
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.0,0.0);
	while(t<360)
	{
		x=xc+r*cos(t);
		y=yc+r*sin(t);
		glVertex2f(x,y);
		t+=1;
	}
	t=0;
	glEnd();
}

void backgrnd()
{
	//sky
	glBegin(GL_POLYGON);
	for(int i=0;i<=3;i++)
	{
		glColor3fv(sky_col[i]);
		glVertex2fv(sky[i]);
	}
	glEnd();
	
//grass
	glBegin(GL_POLYGON);
	glColor3f(0,1,0);
	for(int i=0;i<=20;i++)
    glVertex2fv(grass[i]);
	glEnd();
	
	//ground
	glBegin(GL_POLYGON);
	glColor3f(.7,.5,.4);
	for(int i=0;i<=3;i++)
    glVertex2fv(ground[i]);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	for(int i=0;i<=3;i++)
    glVertex2fv(ground[i]);
	glEnd();

	//white surface1
	glBegin(GL_POLYGON);
	glColor3f(1,1,1);
	for(int i=0;i<=3;i++)
    glVertex2fv(whitesurf1[i]);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(1,0,0);
	for(int i=0;i<=3;i++)
    glVertex2fv(whitesurf1[i]);
	glEnd();

	//red box
    glBegin(GL_POLYGON);
	glColor3f(1,0,0);
	for(int i=0;i<=3;i++)
    glVertex2fv(redbox[i]);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(1,1,1);
	for(int i=0;i<=3;i++)
    glVertex2fv(redbox[i]);
	glEnd();

	//white surface2
	glBegin(GL_POLYGON);
	glColor3f(1,1,1);
	for(int i=0;i<=3;i++)
    glVertex2fv(whitesurf2[i]);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(1,0,0);
	for(int i=0;i<=3;i++)
    glVertex2fv(whitesurf2[i]);
	glEnd();

	//support base
	glBegin(GL_POLYGON);
	glColor3f(0.3,0.3,0.3);
	for(int i=0;i<=3;i++)
    glVertex2fv(sup_base[i]);
	glEnd();

	//support net
	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<=27;i++)
    glVertex2fv(sup_net[i]);
	glEnd();

    //two rods
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
    for(int i=0;i<=3;i++)
    glVertex2fv(left_rod[i]);
	glEnd();
	glBegin(GL_POLYGON);
	for(int i=0;i<=3;i++)
    glVertex2fv(right_rod[i]);
	glEnd();

	//support top
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
    for(int i=0;i<=4;i++)
    glVertex2fv(sup_top[i]);
	glEnd();

	//holding piece
	glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
    for(int i=0;i<=3;i++)
    glVertex2fv(hold_pi[i]);
	glEnd();

	glFlush();
	
}

void rocket()
{
    //head
    glBegin(GL_POLYGON);
	glColor3f(.4,.4,.4);
	for(int i=0;i<=3;i++)
    glVertex2fv(head1[i]);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(.4,.4,.4);
	for(int i=0;i<=3;i++)
    glVertex2fv(head2[i]);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(.4,.4,.4);
	for(int i=0;i<=2;i++)
    glVertex2fv(head3[i]);
	glEnd();
	//black line
	glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	for(int i=0;i<=3;i++)
    glVertex2fv(head1[i]);
	glEnd();
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<=3;i++)
    glVertex2fv(head2[i]);
	glEnd();
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<=2;i++)
    glVertex2fv(head3[i]);
	glEnd();
	 
	//top cylinder
	glBegin(GL_POLYGON);
	glColor3f(.5,.5,.5);
	for(int i=0;i<=3;i++)
    glVertex2fv(topcyl1[i]);
	glEnd();
	//black line
    glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	for(int i=0;i<=3;i++)
    glVertex2fv(topcyl1[i]);
	glEnd();

    //middle cylinder
	glBegin(GL_POLYGON);
	glColor3f(.4,.4,.4);
	for(int i=0;i<=3;i++)
    glVertex2fv(midcyl1[i]);
	glEnd();
	//black line
	glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	for(int i=0;i<=3;i++)
    glVertex2fv(midcyl1[i]);
	glEnd();

	//bottom cylinder
	glBegin(GL_POLYGON);
	glColor3f(.5,.5,.5);
	for(int i=0;i<=3;i++)
    glVertex2fv(botcyl1[i]);
	glEnd();
	//black line
    glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	for(int i=0;i<=3;i++)
    glVertex2fv(botcyl1[i]);
	glEnd();

	//nozzle
	glBegin(GL_POLYGON);
	glColor3f(.4,.4,.4);
	for(int i=0;i<=3;i++)
    glVertex2fv(noz1[i]);
	glEnd();
    //black line
	glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	for(int i=0;i<=3;i++)
    glVertex2fv(noz1[i]);
	glEnd();

	//right piece
	glBegin(GL_POLYGON);
	glColor3f(.35,.35,.35);
	for(int i=0;i<=3;i++)
    glVertex2fv(body1[i]);  //body
	glEnd();
	glBegin(GL_POLYGON);
	for(int i=0;i<=3;i++)
    glVertex2fv(head4[i]);   //head
	glEnd();
	glBegin(GL_POLYGON);
	for(int i=0;i<=3;i++)
    glVertex2fv(head5[i]);
	glEnd();
	glBegin(GL_POLYGON);
	for(int i=0;i<=2;i++)
    glVertex2fv(head6[i]);
	glEnd();
	glBegin(GL_POLYGON);
	for(int i=0;i<=3;i++)
    glVertex2fv(noz2[i]);   //nozzle
	glEnd();
	//right piece black line
	glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	for(int i=0;i<=3;i++)
    glVertex2fv(body1[i]);  //body
	glEnd();
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<=3;i++)
    glVertex2fv(head4[i]);  //head
	glEnd();
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<=3;i++)
    glVertex2fv(head5[i]);
	glEnd();
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<=2;i++)
    glVertex2fv(head6[i]);
	glEnd();
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<=3;i++)
    glVertex2fv(noz2[i]);  //nozzle
	glEnd();


	//left piece
	glBegin(GL_POLYGON);
	glColor3f(.35,.35,.35);
	for(int i=0;i<=3;i++)
    glVertex2fv(body2[i]);  //body
	glEnd();
	glBegin(GL_POLYGON);
	for(int i=0;i<=3;i++)
    glVertex2fv(head7[i]);  //head
	glEnd();
	glBegin(GL_POLYGON);
	for(int i=0;i<=3;i++)
    glVertex2fv(head8[i]);  
	glEnd();
	glBegin(GL_POLYGON);
	for(int i=0;i<=2;i++)
    glVertex2fv(head9[i]);  
	glEnd();
	glBegin(GL_POLYGON);
	for(int i=0;i<=3;i++)
    glVertex2fv(noz3[i]);  //nozzle
	glEnd();
	//left piece black line
	glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	for(int i=0;i<=3;i++)
    glVertex2fv(body2[i]);  //body
	glEnd();
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<=3;i++)
    glVertex2fv(head7[i]);  //head
	glEnd();
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<=3;i++)
    glVertex2fv(head8[i]);
	glEnd();
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<=2;i++)
    glVertex2fv(head9[i]); 
	glEnd();
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<=3;i++)
    glVertex2fv(noz3[i]);  //nozzle
	glEnd();
	
	glFlush();
}

/*-----display of fire------*/
void triangle(point a,point b,point c)
{
	glBegin(GL_POLYGON);
  	glVertex2fv(a);
	glVertex2fv(b);
	glVertex2fv(c);
	glEnd();
}

void smaltri(point v[])
{
	glColor3f(0.9,0.9,0);
	glBegin(GL_TRIANGLES);
	glVertex2fv(v[0]);
	glVertex2fv(v[1]);
	glVertex2fv(v[2]);
	 glEnd();
}
void divide_triangle(point a,point b,point c,int m)
{
	point v1,v2,v3;
	int j;

	if(m>0)
	{
		for(j=0;j<2;j++) v1[j]=(a[j]+b[j])/2;
		for(j=0;j<2;j++) v2[j]=(a[j]+c[j])/2;
		for(j=0;j<2;j++) v3[j]=(b[j]+c[j])/2;
		divide_triangle(a,v1,v2,m-1);
		divide_triangle(c,v2,v3,m-1);
		divide_triangle(b,v3,v1,m-1);
	}
	else
		triangle(a,b,c);
}

void fire(int m,point v[])
{
	smaltri(v);
	glColor3f(1,0,0);
	divide_triangle(v[0],v[1],v[2],m);
	glFlush();
}
/*------end of fire disply function------*/

void frontpage()
{
	backgrnd();
	drawstring(60,470,"WELCOME TO EAST WEST INSTITUTE OF TECHNOLOGY");
	drawstring(70,425,"COMPUTER GRAPHICS PROJECT : MARS MISSION");
	drawstring(240,380,"TEAM MATES");
	drawstring(320,320,"NISCHAL");
	drawstring(60,320,"GOURAV");
	drawstring(130,180,"PRESS C TO CONTINUE AND Q TO QUIT");
}

void dismantle1()
{
	/*-----------remove bottom piece-------*/
	//bottom cylinder
	glBegin(GL_POLYGON);
	for(int i=0;i<=3;i++)
	{
		botcyl1[i][1]=botcyl1[i][1]-5;
	glColor3f(.5,0.5,.5);
    glVertex2fv(botcyl1[i]);
	}
	glEnd();
	
//nozzle
	glBegin(GL_POLYGON);
	for(int i=0;i<=3;i++)
	{
		noz1[i][1]=noz1[i][1]-5;
	glColor3f(.4,0.4,.4);
    glVertex2fv(noz1[i]);
	}
	glEnd();

	rocket();
	fire(n,vbase2);
	fire(n,vnoz2);
	fire(n,vnoz3);

	//stars
	glPointSize(5.0);
	glBegin(GL_POINTS);
	glColor3f(1,1,1);
	for(int i=0;i<=13;i++)
		glVertex2fv(stars[i]);
	glEnd();

	starsfunc();
		
	glFlush();
}

void dismantle2()
{
	/*--------- remove middle cylinder--------*/
		glBegin(GL_POLYGON);
		for(int i=0;i<=3;i++)
		{
			midcyl1[i][1]=midcyl1[i][1]-5;
			glColor3f(.4,0.4,.4);
			glVertex2fv(midcyl1[i]);
		}
	glEnd();

	//right piece
	glBegin(GL_POLYGON);
	for(int i=0;i<=3;i++)
	{
		body1[i][0]=body1[i][0]+5;
		body1[i][1]=body1[i][1]-5;
		glColor3f(.35,.35,.35);
		glVertex2fv(body1[i]);
	}//body
	glEnd();
	glBegin(GL_POLYGON);
	for(int i=0;i<=3;i++)
	{
		head4[i][0]=head4[i][0]+5;
		head4[i][1]=head4[i][1]-5;
		glVertex2fv(head4[i]);   
	}//head
	glEnd();
	glBegin(GL_POLYGON);
	for(int i=0;i<=3;i++)
	{
		head5[i][0]=head5[i][0]+5;
		head5[i][1]=head5[i][1]-5;
		glVertex2fv(head5[i]);
	}
	glEnd();
	glBegin(GL_POLYGON);
	for(int i=0;i<=2;i++)
	{
		head6[i][0]=head6[i][0]+5;
		head6[i][1]=head6[i][1]-5;
		glVertex2fv(head6[i]);
	}
	glEnd();
	glBegin(GL_POLYGON);
	for(int i=0;i<=3;i++)
	{
		noz2[i][0]=noz2[i][0]+5;
		noz2[i][1]=noz2[i][1]-5;
		glVertex2fv(noz2[i]);   
	}//nozzle
	glEnd();

	//left piece
	glBegin(GL_POLYGON);
	for(int i=0;i<=3;i++)
	{
		body2[i][0]=body2[i][0]-5;
		body2[i][1]=body2[i][1]-5;
		glColor3f(.35,.35,.35);
		glVertex2fv(body2[i]);
	}//body
	glEnd();
	glBegin(GL_POLYGON);
	for(int i=0;i<=3;i++)
	{
		head7[i][0]=head7[i][0]-5;
		head7[i][1]=head7[i][1]-5;
		glVertex2fv(head7[i]);   
	}//head
	glEnd();
	glBegin(GL_POLYGON);
	for(int i=0;i<=3;i++)
	{
		head8[i][0]=head8[i][0]-5;
		head8[i][1]=head8[i][1]-5;
		glVertex2fv(head8[i]);
	}
	glEnd();
	glBegin(GL_POLYGON);
	for(int i=0;i<=2;i++)
	{
		head9[i][0]=head9[i][0]-5;
		head9[i][1]=head9[i][1]-5;
		glVertex2fv(head9[i]);
	}
	glEnd();
	glBegin(GL_POLYGON);
	for(int i=0;i<=3;i++)
	{
		noz3[i][0]=noz3[i][0]-5;
		noz3[i][1]=noz3[i][1]-5;
		glVertex2fv(noz3[i]);   
	}//nozzle
	glEnd();

	rocket();
	fire(n,vbase3);

	starsfunc();
}

void dismantle3()
{
	/*-------remove top cylinder--------*/
	glBegin(GL_POLYGON);
	for(int i=0;i<=3;i++)
	{
		topcyl1[i][1]=topcyl1[i][1]-5;
	glColor3f(0.5,0.5,0.5);
    glVertex2fv(topcyl1[i]);
	}
	glEnd();
	
	rocket();

	//stars
	glPointSize(5.0);
	glBegin(GL_POINTS);
	for(int i=0;i<=13;i++)
	{
		stars[i][1]=stars[i][1]-1;
		glColor3f(1,1,1);
		glVertex2fv(stars[i]);
		if(stars[i][1]==0)
			stars[i][1]=450;
	}
	glEnd();
	planet();
	if(yc!=400)
		yc=yc-1;
	glFlush();
}

void release_satellite()
{
	xc=350;yc=250;  //bring planet to center
	glBegin(GL_POLYGON);
	for(int i=0;i<=3;i++)
	{
		head1[i][1]=head1[i][1]-5;
	glColor3f(.4,0.4,.4);
    glVertex2fv(head1[i]);
	}
	glEnd();

	//stars
	glPointSize(5.0);
	glBegin(GL_POINTS);
		glColor3f(1,1,1);
		for(int i=0;i<=13;i++)
		glVertex2fv(stars[i]);
	glEnd();
	rocket();
	planet();
	
	if(t1<450)
	{
		h=xc+r1*cos(t1);
		l=yc+r1*sin(t1);
		glBegin(GL_POLYGON);
		head2[0][0]=h;
		head2[0][1]=l;
		head2[1][0]=h+20;  
		head2[1][1]=l;            //rect head2[]={{345,450},{365,450},{365,460},{345,460}};                                  
		head2[2][0]=h+20;
		head2[2][1]=l+10;
		head2[3][0]=h;
		head2[3][1]=l+10;
		glColor3f(.4,0.4,.4);
		for(int i=0;i<=3;i++)
		glVertex2fv(head2[i]);
		glEnd();

		glBegin(GL_POLYGON);
		head3[0][0]=h;
		head3[0][1]=l+10;
		head3[1][0]=h+20;  //rect head3[]={{345,460},{365,460},{355,470}};
		head3[1][1]=l+10;
		head3[2][0]=h+10;
		head3[2][1]=l+20;
		glColor3f(.4,.4,.4);
		for(int i=0;i<=2;i++)
	    glVertex2fv(head3[i]);
		glEnd();
		//black line
		glBegin(GL_LINE_LOOP);
		head2[0][0]=h;
		head2[0][1]=l;
		head2[1][0]=h+20;  
		head2[1][1]=l;            //rect head2[]={{345,450},{365,450},{365,460},{345,460}};                                  
		head2[2][0]=h+20;
		head2[2][1]=l+10;
		head2[3][0]=h;
		head2[3][1]=l+10;
		for(int i=0;i<=3;i++)
	    glVertex2fv(head2[i]);
		glEnd();
		glBegin(GL_LINE_LOOP);
		head3[0][0]=h;
		head3[0][1]=l+10;
		head3[1][0]=h+20;  //rect head3[]={{345,460},{365,460},{355,470}};
		head3[1][1]=l+10;
		head3[2][0]=h+10;
		head3[2][1]=l+20;
		for(int i=0;i<=2;i++)
		glVertex2fv(head3[i]);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glColor3f(0.4,.4,.4);
		glVertex2f(h+20,l+5);
		glVertex2f(h+25,l+5);
		glVertex2f(h+25,l+8);
		glVertex2f(h+35,l+8);
		glVertex2f(h+35,l);
		glVertex2f(h+25,l);
		glVertex2f(h+25,l+5);
		glVertex2f(h+20,l+5);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glColor3f(0.4,.4,.4);
		glVertex2f(h,l+5);
		glVertex2f(h-5,l+5);
		glVertex2f(h-5,l+8);
		glVertex2f(h-15,l+8);
		glVertex2f(h-15,l);
		glVertex2f(h-5,l);
		glVertex2f(h-5,l+5);
		glVertex2f(h,l+5);
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(h+10,l);
		glVertex2f(h+10,l-5);
		glVertex2f(h+10,l);
		glVertex2f(h,l-5);
		glVertex2f(h+10,l);
		glVertex2f(h+20,l-5);
		glEnd();

		t1-=0.01;
		if(t1==450)
		t1=90;
	}
	

	glFlush();
}
void onair()
{
	//stars
	glPointSize(5.0);
	glBegin(GL_POINTS);
	glColor3f(1,1,1);
	for(int i=0;i<=13;i++)
		glVertex2fv(stars[i]);
	glEnd();

	starsfunc();

	rocket();
	fire(n,vbase);

	glFlush();
}

void launch()
{
	drawstring(430,100,"Press 1 To Dismantle 1st Block");
	/*-----------dark sky movement---------*/
		glBegin(GL_POLYGON);
	for(int i=0;i<=3;i++)
	{
		sky1[i][1]=sky1[i][1]-10;
		glColor3fv(sky_col1[i]);
		glVertex2fv(sky1[i]);
	}
	glEnd();
	
		glBegin(GL_POLYGON);
	for(int i=0;i<=3;i++)
	{
		sky2[i][1]=sky2[i][1]-10;
		glColor3fv(sky_col2[i]);
		glVertex2fv(sky2[i]);
	}
	glEnd();
	
		glBegin(GL_POLYGON);
	for(int i=0;i<=3;i++)
	{
		sky3[i][1]=sky3[i][1]-10;
		glColor3fv(sky_col3[i]);
		glVertex2fv(sky3[i]);
	}
	glEnd();

	/*-----------sky movement---------*/
		glBegin(GL_POLYGON);
	for(int i=0;i<=3;i++)
	{
		sky[i][1]=sky[i][1]-10;
		glColor3fv(sky_col[i]);
		glVertex2fv(sky[i]);
	}
	glEnd();

        /*------------grass movement-------*/
	glBegin(GL_POLYGON);
	for(int i=20;i>=0;i--)
	{
		grass[i][1]=grass[i][1]-10;
		glColor3f(0,1,0);
	    glVertex2fv(grass[i]);
	}
	glEnd();
	    
		/*------ground movement------*/
	glBegin(GL_POLYGON);
		for(int i=3;i>=0;i--)
		{
			ground[i][1]=ground[i][1]-10;
			glColor3f(.7,.5,.4);
			glVertex2fv(ground[i]);
		}	
		glEnd();
			
		//white surface1
		glBegin(GL_POLYGON);
	for(int i=3;i>=0;i--)
	{
		whitesurf1[i][1]=whitesurf1[i][1]-10;
	glColor3f(1,1,1);
	glVertex2fv(whitesurf1[i]);
	}glEnd();
	

	//red box
	glBegin(GL_POLYGON);
	for(int i=3;i>=0;i--)
	{
		redbox[i][1]=redbox[i][1]-10;
	glColor3f(1,0,0);
	glVertex2fv(redbox[i]);
	}glEnd();
	

	//white surface2
		glBegin(GL_POLYGON);
	for(int i=3;i>=0;i--)
	{
		whitesurf2[i][1]=whitesurf2[i][1]-10;
	glColor3f(1,1,1);
	glVertex2fv(whitesurf2[i]);
	}glEnd();
	

	//support base
	glBegin(GL_POLYGON);
	for(int i=3;i>=0;i--)
	{
		sup_base[i][1]=sup_base[i][1]-10;
	glColor3f(0.3,0.3,0.3);
	glVertex2fv(sup_base[i]);
	}glEnd();

	//support net
	glBegin(GL_LINE_LOOP);
	for(int i=27;i>=0;i--)
	{
		sup_net[i][1]=sup_net[i][1]-10;
 		glColor3f(0,0,0);
     	glVertex2fv(sup_net[i]);
	}glEnd();

    //two rods
	glBegin(GL_POLYGON);
	for(int i=3;i>=0;i--)
	{
		left_rod[i][1]=left_rod[i][1]-10;
	glColor3f(0,0,0);
    glVertex2fv(left_rod[i]);
	}glEnd();

	glBegin(GL_POLYGON);
	for(int i=3;i>=0;i--)
	{
		right_rod[i][1]=right_rod[i][1]-10;
	glVertex2fv(right_rod[i]);
	}glEnd();

	//support top
	glBegin(GL_POLYGON);
	for(int i=4;i>=0;i--)
	{
		sup_top[i][1]=sup_top[i][1]-10;
		glColor3f(0,0,0);

	glVertex2fv(sup_top[i]);
	}glEnd();

	//holding piece
	glBegin(GL_LINE_LOOP);
	for(int i=1;i>=0;i--)
		hold_pi[i][0]=hold_pi[i][0]+5;
	for(int i=3;i>=0;i--)
	{
		hold_pi[i][1]=hold_pi[i][1]-10;
	glColor3f(0,0,0);
    glVertex2fv(hold_pi[i]);
	}
	glEnd();

	onair();

	glFlush();
}

void mydisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	if(k=='\0')
		frontpage();

	if(k=='c' || k=='C')
	{
		glClear(GL_COLOR_BUFFER_BIT);
		backgrnd();
		rocket();
		drawstring(80,100,"Press L To Launch");
	}
	if(k=='q' || k=='Q')
	{
		exit(0);
	}
	if(k=='l' || k=='L')
	{
		launch();
		
	}
	
	if(k=='1')
	{
		dismantle1();
		drawstring(430,150,"Press 2 To Dismantle 2nd Block");
	}
	if(k=='2')
	{
		dismantle2();
		glColor3f(1,0,0);
		drawstring(430,200,"Press 3 To Dismantle 3rd Block");
	}
	if(k=='3')
	{
		dismantle3();
		drawstring(400,100,"Press R To Release The Satellite");
	}

	if(k=='r' || k=='R')
	{
		release_satellite();
		drawstring(100,350,"Press Q To QUIT");
	}

	glFlush();
	glutSwapBuffers();

}

void idle()
{
glutPostRedisplay();
}

void myreshape(int w, int h)
{
	glViewport(0,0,w,h);
	glClearColor(0.1,0.1,0.1,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    if(w<=h)
		gluOrtho2D(0.0,500.0,0.0*(float)h/(float)w,500.0*(float)h/(float)w);
		else
		gluOrtho2D(0.0*((float)w/(float)h),500.0*((float)w/(float)h),0.0,500.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{    
     
        glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(1000,700);
	glutInitWindowPosition(0,0);
	glutCreateWindow("THE ROCKET");
	glutDisplayFunc(mydisplay);
	glutReshapeFunc(myreshape);
	glutKeyboardFunc(mykeys);
	glutIdleFunc(idle);
	glutMainLoop();
return 0;
}




