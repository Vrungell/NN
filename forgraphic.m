fid = fopen('input.txt', 'rb');
input_value = [];
while ~feof(fid)
    x = fscanf (fid,'%f');
    input_value = [input_value, x]; %#ok<AGROW>
end

fid = fopen('output.txt', 'rb');
output_value = [];
while ~feof(fid)
    x = fscanf (fid,'%f');
    output_value = [output_value, x]; %#ok<AGROW>
end
disp(length(input_value));
disp(length(output_value));
disp(plot(input_value,output_value));
