#include <iostream>
using namespace std;

int main() {
    int N; // the number of points used to draw the surface of Mars.
    cin >> N; cin.ignore();
    
    int targetX, targetY;
    int oldx = 0;
    int oldy = 0;
    
    for (int i = 0; i < N; i++) {
        int LAND_X; // X coordinate of a surface point. (0 to 6999)
        int LAND_Y; // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
        cin >> LAND_X >> LAND_Y; cin.ignore();

        if (oldy == LAND_Y && LAND_X-oldx >=1000){ 
            targetX = (LAND_X + oldx) / 2;            
            targetY = LAND_Y ;   
        }
        oldy = LAND_Y;
        oldx = LAND_X;
    }
    
    while (1) {
        int X;
        int Y;
        int HS; // the horizontal speed (in m/s), can be negative.
        int VS; // the vertical speed (in m/s), can be negative.
        int F; // the quantity of remaining fuel in liters.
        int R; // the rotation angle in degrees (-90 to 90).
        int P; // the thrust power (0 to 4).
        cin >> X >> Y >> HS >> VS >> F >> R >> P; cin.ignore();

        int power = 0 ;
        int angle = 0 ;
        
        int y = Y - targetY;
        int x = X - targetX;
        
        if (VS < -30) power = 4;

        double landing = x + HS * y / 40 ;

        if (y>200) {
            if      ( landing < -300 ) angle = -20, power = 4 ;
            else if ( landing >  300 ) angle =  20, power = 4 ;
            else if ( HS >  20) angle = 45, power++;
            else if ( HS < -20) angle = -45, power++;
            
            if (HS<-40) angle = -20; // Hack for hi ground level

        }
        
        if (power>4) power = 4;
        cout << angle << " " << power << endl; // R P. R is the desired rotation angle. P is the desired thrust power.
    }
}
