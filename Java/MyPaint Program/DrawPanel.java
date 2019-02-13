// DrawPanel.java
// JPanel that allows the user to draw shapes with the mouse. 
import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Paint;
import java.awt.Stroke;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class DrawPanel extends JPanel
{
   private MyShape shapes[]; // array containing all the shapes
   private int shapeCount; // total number of shapes

   private int shapeType; // the type of shape to draw
   private MyShape currentShape; // the current shape being drawn
   private Paint currentPaint; // the paint of the shape
   private Stroke currentStroke; // the stroke of the current shape
   private boolean filledShape; // whether this shape is filled
   
   private JLabel statusLabel; // label displaying mouse coordinates
   
   // constructor
   public DrawPanel(JLabel status)
   {
      shapes = new MyShape[100]; // create the array
      shapeCount = 0; // initially we have no shapes
      
      setShapeType(0); // initially draw lines
      setDrawingPaint(Color.BLACK); // start drawing with black
      setDrawingStroke(new BasicStroke()); // draw simple thin lines
      setFilledShape(false);// not filled by default
      currentShape = null; // not drawing anything initially
            
      setBackground(Color.WHITE); // set a white background
      
      // add the mouse listeners
      MouseHandler mouseHandler = new MouseHandler();
      addMouseListener(mouseHandler);
      addMouseMotionListener(mouseHandler);
      
      // create a label for the status bar
      statusLabel = status;
   }

   // draw shapes using polymorphism
   public void paintComponent(Graphics g)
   {
      super.paintComponent(g);
      
      Graphics2D g2d = (Graphics2D) g;
      
      for (int i = 0; i < shapeCount; i++)
         shapes[i].draw(g2d);
      
      if (currentShape != null)
         currentShape.draw(g2d);
   }

   // sets the type of shape to draw
   public void setShapeType(int shapeType)
   {
      if (shapeType < 0 || shapeType > 2)
         shapeType = 0;
      
      this.shapeType = shapeType;
   } 

   // sets the drawing paint
   public void setDrawingPaint(Paint paint)
   {
      currentPaint = paint;
   } // end method setDrawingPaint
   
   // sets the current drawing stroke
   public void setDrawingStroke(Stroke stroke)
   {
      currentStroke = stroke;
   } 

   // clears the last shape drawn
   public void clearLastShape()
   {
      if (shapeCount > 0)
      {
         shapeCount--;
         repaint();
      } 
   }

   // clears all drawings on this panel
   public void clearDrawing()
   {
      shapeCount = 0;
      repaint();
   } 

   // sets whether to draw a filled shape
   public void setFilledShape(boolean isFilled)
   {
      filledShape = isFilled;
   } 

   // handles mouse events for this JPanel
   private class MouseHandler extends MouseAdapter
      implements MouseMotionListener
   {
      // creates and sets the initial position for the new shape
      public void mousePressed(MouseEvent e)
      {
         if (currentShape != null)
            return;

         // create the appropriate shape based on shapeType
         switch (shapeType)
         {
            case 0:
               currentShape = new MyLine(e.getX(), e.getY(), e.getX(),
                  e.getY(), currentPaint, currentStroke);      
               break;
            case 1:
               currentShape = new MyOval(e.getX(), e.getY(), e.getX(),
                  e.getY(), currentPaint, currentStroke, filledShape);      
               break;
            case 2:
               currentShape = new MyRect(e.getX(), e.getY(), e.getX(),
                  e.getY(), currentPaint, currentStroke, filledShape);      
               break;
         }
      } 

      // fixes the current shape onto the panel
      public void mouseReleased(MouseEvent e)
      {
         if (currentShape == null)
            return;
         
         // set the second point on the shape
         currentShape.setX2(e.getX());
         currentShape.setY2(e.getY());
         
         // set the shape only if there is room in the array
         if (shapeCount < shapes.length)
         {
            shapes[shapeCount] = currentShape;
            shapeCount++;
         }
         
         currentShape = null; // clear the temporary drawing shape     
         repaint();
      } 

      // update the shape to the current mouse position while dragging
      public void mouseDragged(MouseEvent e)
      {
         if (currentShape != null)
         {
            currentShape.setX2(e.getX());
            currentShape.setY2(e.getY());
            repaint();
         }

         mouseMoved(e); // update status bar
      } 

      // update the status bar to show the current mouse coordinates
      public void mouseMoved(MouseEvent e)
      {
         statusLabel.setText(
            String.format("(%d,%d)", e.getX(), e.getY()));
      } 
   } 
} // end class DrawPanel
