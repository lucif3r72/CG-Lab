#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

int main(){
    int left, top, bottom, right;
    int deg;
    float rad, x1, x2, x3, x4, y1, y2, y3, y4;;
	int xt, yt, xs, ys, shp, mtn;
	int cx, cy, cr, rs;
	int gd = DETECT, gm;

	printf("1. Circle\t2. Quadilateral\n3. Triangle\t4. Polygon\n");
	printf("Enter the shape no. you want to create: ");
	scanf("%d", &shp);

    while(1){
        switch(shp){
            case 1:
                printf("Enter the X, Y Co-ordinates and Radius of Circle:\n");
                scanf("%d%d%d", &cx, &cy, &cr);

                printf("1. Transition\n2. Scaling\n3. Rotation (NOT FOR CIRCLE)\n");
                printf("Enter the motion no. to be done -->");
                scanf("%d", &mtn);

                switch(mtn){
                    case 1:
                        printf("Enter the X, Y Co ordinates for transition:\n");
                        scanf("%d%d", &xt, &yt);

                        initgraph(&gd, &gm, NULL);
                        circle(cx, cy, cr);
                        delay(2000);
                        cleardevice();

                        circle(cx+xt, cy+yt, cr);
                        delay(2000);
                        break;

                    case 2:
                        printf("Enter X, Y co-ordinates and Radius for Scaling:\n");
                        scanf("%d%d%d",&xs, &ys, &rs);

                        initgraph(&gd, &gm, NULL);
                        circle(cx, cy, cr);
                        delay(2000);
                        cleardevice();

                        circle(cx*xs, cy*ys, cr*rs);
                        delay(2000);
                        break;

                    case 3 :
                        exit(0);

                    default:
                        printf("Enter correct choice-->");
                }
            break;

            case 2:
                printf("Enter the Left, Top, Right, Bottom of Quadilateral:\n");
                scanf("%d%d%d%d", &left, &top, &right, &bottom);

                printf("1. Transition\n2. Scaling\n3. Rotation (NOT FOR CIRCLE)\n");
                printf("Enter the motion no. to be done -->");
                scanf("%d", &mtn);

                switch(mtn){
                    case 1:
                        printf("Enter the X, Y Co ordinates for transition:\n");
                        scanf("%d%d", &xt, &yt);

                        initgraph(&gd, &gm, NULL);
                        line(left,bottom,right,bottom);
                        line(left,bottom,left,top);
                        line(right,bottom,right,top);
                        line(left,top,right,top);
                        delay(2000);
                        cleardevice();

                        rectangle(left+xt, top+yt, right+xt, bottom+yt);
                        delay(2000);
                        break;

                    case 2:
                        printf("Enter X, Y co-ordinates for Scaling:\n");
                        scanf("%d%d",&xs, &ys);

                        initgraph(&gd, &gm, NULL);
                        line(left,bottom,right,bottom);
                        line(left,bottom,left,top);
                        line(right,bottom,right,top);
                        line(left,top,right,top);
                        delay(2000);
                        cleardevice();

                        rectangle(left*xt, top*yt, right*xt, bottom*yt);
                        delay(2000);
                        break;

                    case 3 :
                        printf("\nEnter the angle to rotate :");
                        scanf("%d",&deg);
                        rad=deg*(3.14/180);

                        initgraph(&gd, &gm, NULL);

                        x1=left*cos(rad)-bottom*sin(rad);
                        y1=left*sin(rad)+bottom*cos(rad);
                        x2=right*cos(rad)-bottom*sin(rad);
                        y2=right*sin(rad)+bottom*cos(rad);
                        x3=left*cos(rad)-top*sin(rad);
                        y3=left*sin(rad)+top*cos(rad);
                        x4=right*cos(rad)-top*sin(rad);
                        y4=right*sin(rad)+top*cos(rad);

                        line(fabs(x1),fabs(y1),fabs(x2),fabs(y2));
                        line(fabs(x1),fabs(y1),fabs(x3),fabs(y3));
                        line(fabs(x3),fabs(y3),fabs(x4),fabs(y4));
                        line(fabs(x2),fabs(y2),fabs(x4),fabs(y4));
                        getch();
                        cleardevice();

                        break;

                    default:
                        printf("Enter correct choice-->");
                }
            break;

            //case 3:



            default :
                printf("Enter Valid Choice-->");
        }
    }
	closegraph();
	return 0;
}

