close all
clc
clear
hitrate=[0.07 0.20 0.47 0.53];
type=[1 2 3 4];
figure,plot(type,hitrate);
title("Associate:Hit Rate")
xticklabels({'DM','','2W','','4W','','FA'})
xlabel("Way Size")
ylabel("Rate")
missrate=1.-hitrate;
figure,plot(type,missrate);
title("Associate:Miss Rate")
xticklabels({'DM','','2W','','4W','','FA'})
xlabel("Way Size")
ylabel("Rate")

blockhitrate=[0.00 0.10 0.50 0.80];
figure,plot(type,blockhitrate);
title("Bloksize:Hit Rate")
xticklabels({'8','','16','','32','','128'})
xlabel("Block Size")
ylabel("Rate")
blockmissrate=1.-blockhitrate;
figure,plot(type,blockmissrate);
title("Bloksize:Miss Rate")
xticklabels({'8','','16','','32','','128'})
xlabel("Block Size")
ylabel("Rate")


