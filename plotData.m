%                           LEAD Challenge
% Plot data from files mean.log, lowpass.log, modulation.log, sensor.log
% and out.log

mean = load("mean.log");
lowpass = load("lowpass.log");
modulation = load("modulation.log");
sensor = load("sensor.log");
out = load("out.log");


timestamp = mean(:,1);
mean = mean(:,2);
sensor = sensor(:,2);
lowpass = lowpass(:,2);
modulation = modulation(:,2);
out = out(:,2);

plot(timestamp, sensor);
hold on;
plot(timestamp, mean);
hold on;
plot(timestamp, lowpass);
hold on;
plot(timestamp, modulation);
hold on;
plot(timestamp, out);
title('LEAD challenge: modulation, movingAverage and lowPassFilter');
legend({'y = sensor','y = mean', 'y = lowPassFilter','y = modulation', 'y = out'}, 'Location','southeast');

