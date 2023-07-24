#include <iostream>
using namespace std;

struct WinningPlayer{
    enum E{
        X,
        O,
        Stalemante,
        None
    };
};
WinningPlayer::E GetWinningPlyer(){
    return WinningPlayer::X;
}

int main(){
    WinningPlayer::E winningPlayer, something = WinningPlayer::None;
    while(winningPlayer = GetWinningPlyer() == WinningPlayer::None ? WinningPlayer::None : WinningPlayer::Stalemante){
        cout    <<  "Something" <<  "\n";
    }
    

    return 0;
}