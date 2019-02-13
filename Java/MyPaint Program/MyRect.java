// MyRect.java
// Declaration of class MyRect.
import java.awt.Graphics2D;
import java.awt.Paint;
import java.awt.Stroke;

public class MyRect extends MyBoundedShape
{
   // call default superclass constructor
   public MyRect()
   {
      super();
   } 

   // call superclass constructor passing parameters
   public MyRect(int x1, int y1, int x2, int y2,
      Paint paint, Stroke stroke, boolean filled)
   {
      super(x1, y1, x2, y2, paint, stroke, filled);
   }

   // draw rectangle
   public void draw(Graphics2D g2d)
   {
      g2d.setPaint(getPaint());
      g2d.setStroke(getStroke());
      
      if (isFilled())
         g2d.fillRect(getUpperLeftX(), getUpperLeftY(),
            getWidth(), getHeight());
      else
         g2d.drawRect(getUpperLeftX(), getUpperLeftY(),
            getWidth(), getHeight());
   } 
} // end class MyRect
