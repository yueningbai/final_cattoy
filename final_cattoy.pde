import twitter4j.conf.*;
import twitter4j.*;
import twitter4j.auth.*;
import twitter4j.api.*;
import java.util.*;

import processing.serial.*;

PImage img;
PImage img2;
Twitter twitter;
Serial myPort;
float val;
String touchValues = null;
File file = new File("/Users/yuening/Desktop/final_cattoy/kiwi_p.jpg");

//String myText="";

void setup() {
  size(800, 800);
  
  //twitter key
  ConfigurationBuilder cb = new ConfigurationBuilder();
  cb.setOAuthConsumerKey("H42As6tufJLUrOLsxY1RjYMjK");
  cb.setOAuthConsumerSecret("EvJMFEU3jLURopsB7uoJ3wCOKfY5FaVLlHU0qktASrpUqVjaEQ");
  cb.setOAuthAccessToken("988873889043435521-mIn9iqlRDuZLZ0yz93E05uYUjBIdTJ6");
  cb.setOAuthAccessTokenSecret("qMBRKDL0R3ukx3W5BtfcEaYZaStnqhFuA9AcC3TwpsOYl");

  TwitterFactory tf = new TwitterFactory(cb.build());
  twitter = tf.getInstance();
  
  //connect to the port
  myPort = new Serial(this, "/dev/cu.usbmodem1461", 9600);
  myPort.bufferUntil('n');
  
  img= loadImage("kiwi2.png");
  img2= loadImage("gotya.png");
}
//void serialEvent (Serial myPort) {
//  myText = myPort.readStringUntil('n');
//}
void draw() {
  background(0, 0, 0);
  
  //read the sensor value
  if(myPort.available()>0){
    touchValues = myPort.readStringUntil('\n');
      if(touchValues !=null){
      val= float(touchValues);
      println("Val="+val);
      }
    }
    
   sendTweet();
    
    
  }
  
void sendTweet(){
  if(val<200){
    for(int i=0;i<500;i=i+1){
      float r1 = random(5,700);
      float r2 = random(-5,700);
      
      image(img,r1,r2,img.width/2,img.height/2);
    }
    
  }
  if(val>200){
    String randomTweet = "play with me!"+random(100);    
    tweetPic(file, randomTweet);

    image(img2,0,0);
    noLoop();
  }
}
  
  
  
  /*
  if(myPort.available()>0){
    myText = myPort.readStringUntil('\n');
    println(myText);
    if(myText == "YES"){
      tweet();
    }
    }*/




//printArray(Serial.list()); find the port


void tweetPic(File _file, String theTweet)
{
    try
    {
        StatusUpdate status = new StatusUpdate(theTweet);
        status.setMedia(_file);
        twitter.updateStatus(status);
        System.out.println("Status updated to [" + theTweet + "].");
    }
     catch (TwitterException te)
    {
        System.out.println("Error: "+ te.getMessage());
    }
}
