<!DOCTYPE html>
    <html><head><title>ESP8266 Mbed</title></head>
    <body>    
    <div style=text-align:center; background-color:#F4F4F4; color:#00AEDB;><h1>ESP8266 Mbed Web Controller</h1>   
    Hit Count - 
    
    <br>Last Hit - 
                       
    </div><br /><hr>
    <h3>Mbed RTC Time -&nbsp&nbsp             
    
    </h3>rn
    <p><form method=POST><strong> Temperature:&nbsp&nbsp<input type=text size=6 value=
    
    > <sup>O</sup>C <form method=POST> <strong> &nbsp&nbspBattery:&nbsp&nbsp<input type=text size=4 value=
   
    > </sup>V    
    <p><input type=radio name=led1 value=0 checked>  Red LED off
                <br><input type=radio name=led1 value=1 >  Red LED on} 
        <p><input type=radio name=led1 value=0 >  Red LED off
                <br><input type=radio name=led1 value=1 checked>  Red LED on}   
    <p><input type=radio name=Out1 value=0 checked>  Digital Out 1  off
                <br><input type=radio name=Out1 value=1 >  Digital Out 1 on}
        <p><input type=radio name=Out1 value=0 >  Digital Out 1 off
                <br><input type=radio name=Out1 value=1 checked>  Digital Out 1 on}   
    <p><input type=radio name=Out2 value=0 checked>  Digital Out 2 off
                <br><input type=radio name=Out2 value=1 >  Digital Out 2 on}
        <p><input type=radio name=Out2 value=0 >  Digital Out 2 off
                <br><input type=radio name=Out2 value=1 checked>  Digital Out 2 on}           
    <p><input type=radio name=Out3 value=0 checked>  Digital Out 3 off
                <br><input type=radio name=Out3 value=1 >  Digital Out 3 on}
        <p><input type=radio name=Out3 value=0 >  Digital Out 3 off
                <br><input type=radio name=Out3 value=1 checked>  Digital Out 3 on}    
    <p><input type=radio name=In1 value=0 >  Digital In 1}
       <p><input type=radio name=In1 value=1 checked>  Digital In 1}   
    <br><input type=radio name=In2 value=0 >  Digital In 2}
        <br><input type=radio name=In2 value=1 checked>  Digital In 2}           
    <br><input type=radio name=In3 value=0 >  Digital In 3}
       <br><input type=radio name=In3 value=1 checked>  Digital In 3}                  
    </strong><p><input type=submit value=send-refresh style=background: #3498db;    
    background-image:-webkit-linear-gradient(top, #3498db, #2980b9    
    background-image:linear-gradient(to bottom, #3498db, #2980b9
    -webkit-border-radius:12;border-radius: 12px;font-family: Arial;color:#ffffff;font-size:20px;padding:
    10px 20px 10px 20px; border:solid #103c57 3px;text-decoration: none; 
    background: #3cb0fd;
    background-image:-webkit-linear-gradient(top,#3cb0fd,#1a5f8a 
    background-image:linear-gradient(to bottom,#3cb0fd,#1a5f8a
    text-decoration:none;></form></span>
    <p/><h2>How to use:</h2><ul>
    <li>Select the Radio buttons to control the digital out pins.</li>
    <li>Click 'Send-Refresh' to send.</li>      
    <li>Use the 'Send-Refresh' button to refresh the data.</li> 
    </ul>
    </body></html>