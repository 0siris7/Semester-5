import java.awt.*;
import java.applet.*;
public class samplecolor extends Applet
{
String msg;
public void init()
{
SetBackground(color.cyan);
SetForeground(color.red);
msg="Inside init()--";
}
public void start()
{
msg+="Inside start()--";
}
public void stop()
{
msg+="Inside stop()--";
} 
public void paint(Graphics g)
{msg+="Inside paint()--";
g.drawString(msg,20,20);
}

}