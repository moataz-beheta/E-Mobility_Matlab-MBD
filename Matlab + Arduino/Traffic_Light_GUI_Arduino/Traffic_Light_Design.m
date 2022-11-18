function Traffic_Light_Design()
%% Stand %%
x = [9     11      11      9       9];      %(9,0) => (11,0) => (11,10) => (9,10) => (9,0)
y = [0      0      10      10      0];
Gray_RGB = [0.75 0.75 0.75];
fill(x,y,Gray_RGB);
hold on;

%% Frame %%
x = [7     13      13      7       7];      %(7,10) => (13,10) => (13,30) => (7,30) => (7,10)
y = [10    10      30     30      10];    
fill(x,y,'k');

%% Labels and Limits %%
xlim([0 20]);
ylim([0 35]);
pbaspect([1 1.5 1]);
end