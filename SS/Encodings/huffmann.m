clc;
clear all;
close all;
    
alphabet = {'a' 'b' 'c' 'd' 'e' 'f' 'g' };
prob =[0.10 0.25 0.05 0.32 0.01 0.07 0.2];
randsrc_ = ['a','g','c'];
dict    = huffmandict_( alphabet, prob );
display(dict);
encoded = huffmanenco_( randsrc_, dict);
display(encoded);
decoded = huffmandeco_( encoded, dict);
display(decoded);
 length( encoded )
 code_eff=eff_calc(dict,prob)


function deco = huffmandeco_( sig, dict)
deco = []; % Output signal vector initialize.
    sig_ = sig;
    codepos_ = 1;
    while( ~isempty(sig_) ) % For each set of bits in the signal.
        temp_ = sig_(codepos_); % Get first bit(char). 
        dictb = dict; % Get a backup of the input dictionary.
        while (1) % Loop
            [flag,dict_] = found_match( temp_, codepos_, dictb); % Get a sub dictionary.
            dictb = dict_; % Update loop dictionary.
            if ( length(dictb.code) ~= 1 ) % Until one codeword left.
                codepos_ = codepos_ + 1;   % Match second bit(char).
                temp_ = sig_(codepos_);    % Get first char 
            else % Found the symbol
                codepos_ = 1; % Reset position.
                sig_ = sig_(length(dictb.code{1})+1:end); % Update the input signal.
                break;
            end        
        end
        deco = [deco dictb.symbol]; % Append char to decoded signal.
    end
end

function enco = huffmanenco_( sig, dict)
dictLength = length(dict.code);
enco = ''; % Empty encoded signal (char).
  while( ~isempty(sig) ) % Loop for each signal value.
        tempcode = ''; % Empty signal value (char).
        for j = 1 : dictLength 
            % Search sequentially through the dictionary to
            % find the proper code for the given signal.
             if( strcmp(sig(1),dict.symbol{j}) ) % If there is a match.
                 tempcode = dict.code{j};
                  break;
             end
        end
        enco = strcat( enco,tempcode ); % Append the code to the encryption message.
        sig = sig(2:end); % Update the signal vector.
  end
end

function dict = huffmandict_( alphabet, prob )
 for i = 1:length( prob )    % For each probability.
        codewords{i} = '';      % Create an empty codeword.
        symbol{i} = i;      
 end
 while ( prob ~= 1 ) % Loop, until we reach the root.
        % Sort the probabilities at every loop.
        [~, arr] = sort(prob);  % Get arrangement of the sorted probabilities.
        % Get the index of the two sets to be merged.
        last = arr(1);
        next = arr(2);
        % Get their main index or indexes.
        right_set = symbol{last};
        left_set  = symbol{next};
        % Get their probabilities.
        right_probability = prob(last); 
        left_probability  = prob(next); 
        % Append them in a new set.
        merged_set = [right_set, left_set]; 
        new_prob   = right_probability + left_probability;
       symbol(arr(1:2)) = '';
        prob(arr(1:2))   = '';
        symbol = [symbol merged_set];
        prob   = [prob new_prob];     
        % Get the updated codeword.
        codewords = append_(codewords,right_set,'1');
        codewords = append_(codewords,left_set,'0');
end
    dict.symbol = alphabet; dict.code = codewords;
end

function codewords = append_(codewords,input_set,input_code)
    for i = 1:length(input_set)
        codewords{input_set(i)} = strcat(input_code,codewords{input_set(i)});      
    end
end

 function [flag,dict_] = found_match( code, pos, dict )
        dict_.symbol={}; dict_.code={}; % Create a dictionary structure.
        j = 1;    % Iterator.
        flag = 0; % Flag for error.
        for i = 1:length(dict.code) % For each code in dictionary.
            if ( strcmp(dict.code{i}(pos), code) ) % If inpute code matches 
                 flag = 1; % No error match.
                 dict_.symbol(j) = dict.symbol(i); % Get the symbol that matches.
                 dict_.code(j) = dict.code(i);     % Get the code of the matched symbol.
                 j = j + 1;                        % Prepare for a next symbol.
            end
        end
 end
    
 function out_ = eff_calc( dict, prob )
    % Calculate average length code.
    out_ = average_cdl( dict, prob );
    disp('avg cdl');
    disp(out_);
    % Calculate entropy.
    hu = 0;
    for i = 1:length(prob);
        hu = hu - prob(i)*log2(prob(i));
    end
      disp('entropy');
    disp(hu);
    out_ = hu/out_;
end

function out_ = average_cdl( dict, prob )
    out_ = 0;
    for i = 1:length(dict.symbol);
        out_ = out_ + prob(i)*length(dict.code{i});
    end
end
