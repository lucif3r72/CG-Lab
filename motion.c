#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

int main(){
    int n, no, arr[1000];                               //for polygon
    int x[3], y[3], i;                                  //for triangle
    int left, top, bottom, right;                       //for rectangle
    int deg;                                            //degree of rotation
    float rad, x1, x2, x3, x4, y1, y2, y3, y4;          //radian value & rotation co ordinates
	int xt, yt, shp, mtn;                               //global variable for 2Dtransforms
	float xs, ys, rs;                                   //global variable for 2Dtransforms
	int cx, cy, cr;                                 	//for circle
	int gd = DETECT, gm;

	printf("1. Circle\t2. Quadilateral\n3. Triangle\t4. Polygon\n");
	printf("Enter the shape no. you want to create: ");
	scanf("%d", &shp);

    while(1){
        switch(shp){
            case 1:
                printf("Enter the X, Y Co-ordinates and Radius of Circle:\n");
                scanf("%d%d%d", &cx, &cy, &cr);

                printf("1. Translation\n2. Scaling\n3. Rotation (NOT FOR CIRCLE)\n");
                printf("Enter the motion no. to be done -->");
                scanf("%d", &mtn);

                switch(mtn){
                    case 1:
                        printf("Enter the X, Y Co ordinates for translation:\n");
                        scanf("%d%d", &xt, &yt);

                        initgraph(&gd, &gm, NULL);
                        setcolor(3);
                        circle(cx, cy, cr);             //normal circle
                        delay(2000);
                        cleardevice();

                        setcolor(5);
                        circle(cx+xt, cy+yt, cr);       //translated circle
                        delay(2000);
                        break;

                    case 2:
                        printf("Enter X, Y co-ordinates and Radius for Scaling:\n");
                        scanf("%f%f%f",&xs, &ys, &rs);

                        initgraph(&gd, &gm, NULL);
                        setcolor(3);
                        circle(cx, cy, cr);             //normal circle
                        delay(2000);
                        cleardevice();

                        setcolor(5);
                        circle(cx*xs, cy*ys, cr*rs);    //scaled circle
                        delay(2000);
                        break;

                    case 3 :
                        exit(0);                        //exit for no rotation

                    default:
                        printf("Enter correct choice-->");
                }
            break;

            case 2:
                printf("Enter the Left, Top, Right, Bottom of Quadilateral:\n");
                scanf("%d%d%d%d", &left, &top, &right, &bottom);

                printf("1. Translation\n2. Scaling\n3. Rotation (NOT FOR CIRCLE)\n");
                printf("Enter the motion no. to be done -->");
                scanf("%d", &mtn);

                switch(mtn){
                    case 1:
                        printf("Enter the X, Y Co ordinates for translation:\n");
                        scanf("%d%d", &xt, &yt);

                        initgraph(&gd, &gm, NULL);
                        setcolor(3);
                        line(left,bottom,right,bottom);                     //normal quadilateral
                        setcolor(3);
                        line(left,bottom,left,top);
                        setcolor(3);
                        line(right,bottom,right,top);
                        setcolor(3);
                        line(left,top,right,top);
                        delay(2000);
                        cleardevice();

                        setcolor(5);
                        rectangle(left+xt, top+yt, right+xt, bottom+yt);    //translated quadilateral
                        delay(2000);
                        break;

                    case 2:
                        printf("Enter X, Y co-ordinates for Scaling:\n");
                        scanf("%f%f",&xs, &ys);

                        initgraph(&gd, &gm, NULL);
                        setcolor(3);
                        line(left,bottom,right,bottom);                     //normal quadilateral
                        setcolor(3);
                        line(left,bottom,left,top);
                        setcolor(3);
                        line(right,bottom,right,top);
                        setcolor(3);
                        line(left,top,right,top);
                        delay(2000);
                        cleardevice();

                        setcolor(5);
                        rectangle(left*xt, top*yt, right*xt, bottom*yt);    //scaled quadilateral
                        delay(2000);
                        break;

                    case 3 :
                        printf("\nEnter the angle to rotate :");
                        scanf("%d",&deg);
                        rad=deg*(3.14/180);

                        initgraph(&gd, &gm, NULL);

                        x1=left*cos(rad)-bottom*sin(rad);                   //angles to rotate
                        y1=left*sin(rad)+bottom*cos(rad);
                        x2=right*cos(rad)-bottom*sin(rad);
                        y2=right*sin(rad)+bottom*cos(rad);
                        x3=left*cos(rad)-top*sin(rad);
                        y3=left*sin(rad)+top*cos(rad);
                        x4=right*cos(rad)-top*sin(rad);
                        y4=right*sin(rad)+top*cos(rad);

                        setcolor(3);
                        line(fabs(x1),fabs(y1),fabs(x2),fabs(y2));          //combing of lines to quadilateral
                        setcolor(3);
                        line(fabs(x1),fabs(y1),fabs(x3),fabs(y3));
                        setcolor(3);
                        line(fabs(x3),fabs(y3),fabs(x4),fabs(y4));
                        setcolor(3);
                        line(fabs(x2),fabs(y2),fabs(x4),fabs(y4));
                        getch();
                        cleardevice();

                        break;

                    default:
                        printf("Enter correct choice-->");
                }
            break;

            case 3:

                printf("Enter the X, Y co ordinates:\n");
                for (i=0; i<3 ; i++){
                printf("X%d:",i+1);     //X co ordinates
                scanf("%d",&x[i]);
                }

                for (i=0; i<3 ; i++){
                printf("Y%d:",i+1);     //Y co ordinates
                scanf("%d",&y[i]);
                }

                printf("1. Translation\n2. Scaling\n3. Rotation (NOT FOR CIRCLE)\n");
                printf("Enter the motion no. to be done -->");
                scanf("%d", &mtn);

                switch(mtn){
                    case 1:
                        printf("Enter the X, Y Co ordinates for translation:\n");
                        scanf("%d%d", &xt, &yt);

                        initgraph(&gd, &gm, NULL);

                        setcolor(3);
                        line(x[0], y[0], x[1], y[1]);                   //normal triangle
                        setcolor(3);
                        line(x[0], y[0], x[2], y[2]);
                        setcolor(3);
                        line(x[1], y[1], x[2], y[2]);
                        delay(1000);
                        cleardevice();

                        setcolor(5);
                        line(x[0]+xt, y[0]+yt, x[1]+xt, y[1]+yt);       //translated triangle
                        setcolor(5);
                        line(x[0]+xt, y[0]+yt, x[2]+xt, y[2]+yt);
                        setcolor(5);
                        line(x[1]+xt, y[1]+yt, x[2]+xt, y[2]+yt);
                        delay(1000);
                        break;

                    case 2:
                        printf("Enter X, Y co-ordinates for Scaling:\n");
                        scanf("%f%f",&xs, &ys);

                        initgraph(&gd, &gm, NULL);

                        setcolor(3);
                        line(x[0], y[0], x[1], y[1]);                   //normal triangle
                        setcolor(3);
                        line(x[0], y[0], x[2], y[2]);
                        setcolor(3);
                        line(x[1], y[1], x[2], y[2]);
                        delay(1000);
                        cleardevice();

                        setcolor(5);
                        line(x[0]*xt, y[0]*yt, x[1]*xt, y[1]*yt);       //scaled triangle
                        setcolor(5);
                        line(x[0]*xt, y[0]*yt, x[2]*xt, y[2]*yt);
                        setcolor(5);
                        line(x[1]*xt, y[1]*yt, x[2]*xt, y[2]*yt);
                        delay(1000);
                        break;

                    /*case 3:
                        printf("\nEnter the angle to rotate :");
                        scanf("%d",&deg);
                        rad=deg*(3.14/180);
                    */

                    default :
                    printf("Enter Valid Choice-->");

                }
				break;

                case 4:

                    printf("Enter the sides of Polygon:\n");
                    scanf("%d",&n);

                    /*printf("1. Translation\n2. Scaling\n3. Rotation (NOT FOR CIRCLE)\n");
                    printf("Enter the motion no. to be done -->");
                    scanf("%d", &mtn);

                    switch(mtn){
                        printf("Enter the X, Y Co ordinates for translation:\n");
                        scanf("%d%d", &xt, &yt);
                    */
                    no= (n*2)+2;
                    printf("enter the co ordinates of polygon:\n");
                    for (i=0; i<no ;i++){
                        scanf("%d", &arr[i]);
                    }

                    initgraph(&gd, &gm, NULL);
                    setcolor(3);
                    drawpoly(n+1, arr);				//polygon drawing function
                    delay(1000);
                    //cleardevice();

                    //drawpoly(n+1, arr+)

                break;

                default :
                	printf("Enter Valid Choice-->");
            }
    }
	return 0;
}

