function decrypt(text)
clc;
close all;
key = [4 1;3 7];
key(1,2) = -key(1,2);
key(2,1) = -key(2,1);
temp = key(1,1);
key(1,1) = key(2,2);
key(2,2) = temp;
[~, C, ~] = gcd(key(1,1)*key(2,2)-key(1,2)*key(2,1),26);
d = mod(C,26);
key = mod(d*key, 26);
a = double(text);
b = reshape(a,2,length(text)/2);
b = b - 65;
y = mod(key*(b),26) + 65;
new_msg = reshape(y,1,length(text));
new_msg = char(new_msg)
end