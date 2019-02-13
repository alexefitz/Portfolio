// DrawFrame.java
// Program that creates a panel for the user to draw shapes.
//Allows the user to choose the shape and set various Java2D options
import java.awt.BasicStroke;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.GradientPaint;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JColorChooser;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class DrawFrame extends JFrame
    implements ItemListener, ActionListener
{
    // Array of possible shapes
    private String shapes[] = {"Line", "Oval", "Rectangle"};
    
    private DrawPanel drawPanel; // the panel that handles the drawing
    
    private JButton undoButton; // button to undo the last shape drawn
    private JButton clearButton; // button to clear all shapes
    private JComboBox<String> shapeChoices; // combo box for selecting shapes
    private JCheckBox filledCheckBox; // check box to toggle filled shapes
    
    private JButton color1Button; //button to choose the first color
    private JButton color2Button; //button to choose the second color
    private JCheckBox gradientCheckBox; // check box to toggle gradients
    
    private JTextField lineWidthField; // text field for the line width
    private JTextField dashLengthField; // text field for the dash length
    private JCheckBox dashedCheckBox; // check box to toggle dashed lines
    
    private Color color1; // first color
    private Color color2; // second color used only in the gradient
    
    //constructor, sets up the components in the frame
    public DrawFrame()
    {
        super("Java 2D Drawings"); // set the title by calling super
        
        //create the top panel that contains all the drawing options
        JPanel topPanel = new JPanel(new GridLayout(2, 1));
        
        //add the top panel to the frame
        topPanel.add(createStandardPanel());
        topPanel.add(createJava2dPanel());
        add(topPanel, BorderLayout.NORTH);
        
        //create a label for the status bar
        JLabel statusLabel = new JLabel("(0,0)");
        
        //add the status bar at the bottom 
        add(statusLabel, BorderLayout.SOUTH);
        
        //create the DrawPanel with its status bar label
        drawPanel = new DrawPanel(statusLabel);
        
        add(drawPanel); // add the drawing area to the center
        
        // set initial drawing options
        setDrawingPaint();
        setDrawingStroke();
    }
    
    //create the JPanel with components for the standard drawing options
    private JPanel createStandardPanel()
    {
        // create a JPanel
        JPanel standardOptions = new JPanel(new FlowLayout());
        
        //create a button for clearing the last drawing
        undoButton = new JButton("Undo");
        undoButton.addActionListener(this);
        standardOptions.add(undoButton);
        
        //create a button for clearing all drawings
        clearButton = new JButton("Clear");
        clearButton.addActionListener(this);
        standardOptions.add(clearButton);
        
        //create a combobox for choosing shapes
        standardOptions.add(new JLabel("Shape:"));
        shapeChoices = new JComboBox<String>(shapes);
        shapeChoices.addItemListener(this);
        standardOptions.add(shapeChoices);
        
        //create a checkbox to determine whether the shape is filled
        filledCheckBox = new JCheckBox("Filled");
        filledCheckBox.addItemListener(this);
        standardOptions.add(filledCheckBox);
        
        return standardOptions;
    }
    
    //create the JPanel with components for the Java2D options
    private JPanel createJava2dPanel()
    {
        //create a JPanel
        JPanel java2dOptions = new JPanel(new FlowLayout());
        
        //create a checkbox to determine whether a gradient is used
        gradientCheckBox = new JCheckBox("Use Gradient");
        gradientCheckBox.addActionListener(this);
        java2dOptions.add(gradientCheckBox);
        
        //create a combobox for choosing the first color
        color1Button = new JButton("1st Color...");
        color1Button.addItemListener(this);
        color1 = Color.BLACK;
        java2dOptions.add(color1Button);
        
        //create a combobox for choosing the first color
        color2Button = new JButton("2nd Color...");
        color2Button.addItemListener(this);
        color2 = Color.BLACK;
        java2dOptions.add(color1Button);
        
        //create a textfield for entering in line width
        java2dOptions.add(new JLabel("Line width:"));
        lineWidthField = new JTextField("1.0", 2);
        lineWidthField.addActionListener(this);
        java2dOptions.add(lineWidthField);
        
        //create a textfield for entering in dash length
        java2dOptions.add(new JLabel("Dash Length:"));
        dashLengthField = new JTextField("10", 2);
        dashLengthField.addActionListener(this);
        java2dOptions.add(dashLengthField);
        
        //create a checkbox to determine whether the shape is filled
        dashedCheckBox = new JCheckBox("Filled");
        dashedCheckBox.addItemListener(this);
        java2dOptions.add(dashedCheckBox);
        
        return java2dOptions;
    }
    
    //handle selections made to a combo box or check box
    public void itemStateChanged(ItemEvent e)
    {
        if (e.getSource() == shapeChoices) // choosing a shape
            drawPanel.setShapeType(shapeChoices.getSelectedIndex());
        else if (e.getSource() == filledCheckBox) //filled/unfilled
            drawPanel.setFilledShape(filledCheckBox.isSelected());
        else if (e.getSource() == gradientCheckBox) // use/no gradient
            setDrawingPaint();
        else if (e.getSource() == dashedCheckBox);//dashed/solid
            setDrawingStroke();
    }
    
    //handle button clicks
    public void actionPerformed(ActionEvent e)
    {
        if(e.getSource() == undoButton) // undo last shape
            drawPanel.clearLastShape();
        else if(e.getSource() == clearButton) // clear all shapes
            drawPanel.clearDrawing();
        else if (e.getSource() == color1Button) // set 1st color
        {
            Color temp =
                JColorChooser.showDialog(this, "Choose a color", color1);
                
            if (temp != null) // check if the user pressed cancel
                color1 = temp;
            
            setDrawingPaint();
        }
        else if(e.getSource() == color2Button) // set a 2nd color
        {
            Color temp =
                JColorChooser.showDialog(this, "Choose a color", color2);
                
            if (temp != null) // check if the user pressed cancel
                color2 = temp;
            
            setDrawingPaint(); 
        }
        else if (e.getSource() == lineWidthField) // set line width
            setDrawingStroke();
        else if (e.getSource() == dashLengthField) // set dash length
            setDrawingStroke();
    }
    
    // sets the Paint for the drawing panel
    private void setDrawingPaint()
    {
        if (gradientCheckBox.isSelected())
            drawPanel.setDrawingPaint(
                new GradientPaint(0, 0, color1, 50, 50, color2, true));
        else // use color1 if there is no gradient
            drawPanel.setDrawingPaint(color1);
    }
    
    //sets the Stroke for the current drawing panel
    private void setDrawingStroke()
    {
        float width = Float.parseFloat(lineWidthField.getText());
        
        if (dashedCheckBox.isSelected())
        {
            float dashes[] = 
                { Float.parseFloat(dashLengthField.getText()) };
            
            drawPanel.setDrawingStroke(new BasicStroke(
                width, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND,
                10, dashes, 0));
        }
        else
            drawPanel.setDrawingStroke(new BasicStroke(
                width, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND));
    }
} // end class DrawFrame