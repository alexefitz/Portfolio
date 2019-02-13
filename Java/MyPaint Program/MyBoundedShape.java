// MyBoundedShape.java
// Declaration of class MyBoundedShape.
import java.awt.Paint;
import java.awt.Stroke;

public abstract class MyBoundedShape extends MyShape
{
   private boolean filled; // whether this shape is filled
   
   // call default superclass constructor
   public MyBoundedShape()
   {
      super();
      setFilled(false);
   } 

   // call superclass constructor passing parameters
   public MyBoundedShape(int x1, int y1, int x2, int y2,
      Paint paint, Stroke stroke, boolean filled)
   {
      super(x1, y1, x2, y2, paint, stroke);
      this.filled = filled;
   }

   // get upper left x-coordinate
   public int getUpperLeftX()
   {
      return Math.min(getX1(), getX2());
   } 

   // get upper left y-coordinate
   public int getUpperLeftY()
   {
      return Math.min(getY1(), getY2());
   }

   // get shape width
   public int getWidth()
   {
      return Math.abs(getX2() - getX1());
   }

   // get shape height
   public int getHeight()
   {
      return Math.abs(getY2() - getY1());
   }

   // whether this shape is filled
   public boolean isFilled()
   {
      return filled;
   }

   // set whether this shape is filled
   public void setFilled(boolean isFilled)
   {
      filled = isFilled;
   }
} // end class MyBoundedShape
