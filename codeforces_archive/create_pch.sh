#g++ -std=c++11 -Winvalid-pch -x c++-header -g -O2 -o ./stdc++.h.gch /usr/include/i386-linux-gnu/c++/4.9/bits/stdc++.h
#g++ -std=c++11 -Winvalid-pch -x c++-header -g -O2 -o ./stdc++.h.gch /usr/include/x86_64-linux-gnu/c++/4.9/bits/stdc++.h
g++ -std=c++11 -Winvalid-pch -x c++-header -g -O2 -o ./stdc++.h.gch /usr/include/x86_64-linux-gnu/c++/4.8/bits/stdc++.h
#g++ -std=c++11 -Winvalid-pch -x c++-header -g -O2 -o ./stdc++.h.gch /usr/include/x86_64-linux-gnu/c++/5/bits/stdc++.h

printf "\nbuild time: $SECONDS\n"
