#include <stdio.h>
#include <graphics.h>

int main(){
	int gd = DETECT, gm;
	int t_fact, col, tx = 20;

	initgraph(&gd, &gm, NULL);
	for(t_fact = 0; t_fact < 121; t_fact++){

			//carbody

			for(col = 1; col < 16 ; col++){
				setcolor(col+1);
				line(0 + tx, 320,-320 + tx,320);
				setcolor(col+1);
				line(0 + tx, 320,0 + tx,270);
				setcolor(col+1);
				line(-320 +tx,320,-320 + tx,270);
				setcolor(col+1);
				line(0 +tx,270,-320 + tx,270);
				if (col == 15)
                    col = 2;
				delay(1000);
			}

            //windows

            for(col = 1; col < 16 ; col++){
				setcolor(col);
				line(-120 + tx, 220, -50 + tx, 270);		//front
				setcolor(col);
				line(-220 + tx, 220, -120 + tx, 220);		//top
				setcolor(col);
				line(-250 + tx, 270, -220 + tx, 220);		//back
				setcolor(col);
				line(-220 + tx, 270, -220 + tx, 220);		//backwindow
				setcolor(col);
				line(-120 + tx, 220, -120 + tx, 270);		//frontwindow
				if (col == 15)
                    col = 1;
				delay(1000);
			}

            //frontwheel

            for(col = 1; col < 16 ; col++){
				setcolor(col+2);
				circle(-60 + tx, 350, 30);
				if (col == 15)
                    col = 1;
				delay(1000);
			}

			//backwheel
			for(col = 1; col < 16 ; col++){
				setcolor(col+2);
				circle(-260 + tx, 350, 30);
				if (col == 15)
                    col = 1;
				delay(1000);
			}

			tx = tx + 5;
			delay(50);
			cleardevice();
		}

	closegraph();
	return 0;
}
