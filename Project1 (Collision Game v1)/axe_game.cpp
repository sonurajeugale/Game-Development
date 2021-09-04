#include "raylib.h"

int main()
{
   int x; 
   // window dimension
   int width = {800};
   int height = {450};
   InitWindow(width, height, "Game Window");  //(width, height, title)

   //circle coordinates
   int circle_x{200};
   int circle_y{200};
   int circle_r{25};

   //circle edges
   int l_circle_x{circle_x - circle_r};
   int r_circle_x{circle_x + circle_r};
   int u_circle_y{circle_y - circle_r};
   int b_circle_y{circle_y + circle_r};



   //axe coordinate
   int axe_x{400};
   int axe_y{0};
   int axe_length{50};

   //axe edges
   int r_axe_x{axe_x + axe_length};
   int l_axe_x{axe_x};
   int u_axe_y{axe_y};
   int b_axe_y{axe_y + axe_length};


   int direction{10};


   bool collision_with_axe = 
                     (b_axe_y >= u_circle_y) && 
                     (u_axe_y <= b_circle_y) && 
                     (r_axe_x >= l_circle_x) && 
                     (l_axe_x <= r_circle_x);

   SetTargetFPS(60);
   while (x)
   {
      x = WindowShouldClose() == false; //for window table to close
      
      BeginDrawing();  
      ClearBackground(WHITE); //background colour

      if(collision_with_axe)
      {
         DrawText("Game Over!", 400, 200, 20, RED);
      }
      else
      {
      //Game Logic Begins
     
      //update the edges
      l_circle_x = circle_x - circle_r;
      r_circle_x = circle_x + circle_r;
      u_circle_y = circle_y - circle_r;
      b_circle_y = circle_y + circle_r;

      //update the axe
      l_axe_x = axe_x;
      r_axe_x = axe_x + axe_length;
      u_axe_y = axe_y;
      b_axe_y = axe_y + axe_length;

      //update collision with axe;
      collision_with_axe = 
                     (b_axe_y >= u_circle_y) && 
                     (u_axe_y <= b_circle_y) && 
                     (r_axe_x >= l_circle_x) && 
                     (l_axe_x <= r_circle_x);


      DrawCircle(circle_x, circle_y, circle_r, BLUE); //drawing circle in window 
      DrawRectangle(axe_x,axe_y, axe_length, axe_length, RED); //drawing rectangle in window

      //move the axe
      axe_y  += direction;

      //control the axe in frame 
      if(axe_y > height || axe_y < 0)
      {
         direction = -direction;
      }


      // Moving circle around window 
      if (IsKeyDown(KEY_D) && circle_x < width) 
      {
         circle_x += 10;
      }

      if(IsKeyDown(KEY_A) && circle_x > 0)
      {
         circle_x  -= 10;

      }

      if(IsKeyDown(KEY_W) && circle_y > 0)
      {
         circle_y  -= 10;
      }

      if(IsKeyDown(KEY_S) && circle_y < height)
      {
         circle_y += 10;
      }

      //Game Logic Ends
      }
      
      EndDrawing();
   }

}