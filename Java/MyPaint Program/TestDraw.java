//TestDraw.java
//Test application to display a DrawFrame
import javax.swing.JFrame;

public class TestDraw
{
    public static void main(String[] args)
    {
        DrawFrame application = new DrawFrame();
        application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        application.setSize(600, 400);
        application.setVisible(true);
    }
}//end class TestDraw