function Turn_Off_All_Lights ()
    global radius;
    global th;
    global Dark_Red_RGB;
    global Dark_Yellow_RGB;
    global Dark_Green_RGB;
    global arduinoObject;
    global Red_Light_Pin;
    global Yellow_Light_Pin;
    global Green_Light_Pin;
    
    writeDigitalPin(arduinoObject,Red_Light_Pin,0); 
    writeDigitalPin(arduinoObject,Yellow_Light_Pin,0); 
    writeDigitalPin(arduinoObject,Green_Light_Pin,0);
    
    Dark_Red_RGB= [0.45 0 0];
    Dark_Yellow_RGB= [0.45 0.45 0];
    Dark_Green_RGB= [0 0.45 0];

    
    % Red circle %
    Origin_x= 10;
    Origin_y= 25;
    x = radius * cos(th) + Origin_x;
    y = radius * sin(th) + Origin_y;
    fill(x,y,Dark_Red_RGB);
    
    % Yellow circle %
    Origin_x= 10;
    Origin_y= 20;
    x = radius * cos(th) + Origin_x;
    y = radius * sin(th) + Origin_y;
    fill(x,y,Dark_Yellow_RGB);
    
    % Green circle %
    Origin_x= 10;
    Origin_y= 15;
    x = radius * cos(th) + Origin_x;
    y = radius * sin(th) + Origin_y;
    fill(x,y,Dark_Green_RGB);
end