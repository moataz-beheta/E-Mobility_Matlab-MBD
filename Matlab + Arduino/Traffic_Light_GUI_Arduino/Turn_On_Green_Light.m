function Turn_On_Green_Light()
    global radius;
    global th;
    global arduinoObject;
    global Red_Light_Pin;
    global Yellow_Light_Pin;
    global Green_Light_Pin;
    
    writeDigitalPin(arduinoObject,Red_Light_Pin,0); 
    writeDigitalPin(arduinoObject,Yellow_Light_Pin,0); 
    writeDigitalPin(arduinoObject,Green_Light_Pin,1);
    
    Light_Green_RGB= 'g';

    
    % Red circle %
    Origin_x= 10;
    Origin_y= 15;
    x = radius * cos(th) + Origin_x;
    y = radius * sin(th) + Origin_y;
    fill(x,y,Light_Green_RGB);
    
end