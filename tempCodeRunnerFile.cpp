string buffer = "";
    vector<string> output {};
    for (int i = 0; i < input.length(); ++i) {
        if (input.substr(i, 1) == "-") {
            output.push_back(buffer);
            if (output.size() != 0 &&(output[output.size() - 1] == ")" || isNumber(output[output.size() - 1]))) {
                output.push_back(input.substr(i, 1));
                buffer = "";
            }
            else {
                bool paren = false;
                if (output[output.size() - 1] == "^") {
                    output.push_back("(");
                    
                    paren = true;
                }
                buffer = "-1";
                output.push_back(buffer);
                buffer = "";
                output.push_back("*");
            }
        }