![Screenshot 2025-02-04 231420](https://github.com/user-attachments/assets/a2eee12a-36d4-422d-979f-afe36c21eff8)# Level 3 - Question 1 

Description:
<br>
The traveler discovers that an old friend is stranded in Cultus, a world besieged by the Legion of Astral Toilets. Finding this friend is of the utmost importance—a task shrouded in peril and urgency.

As you enter the chaotic airspace of Cultus, a sudden alert jolts your console. A message arrives—but it is not from the Legion. Something else, lurking in the void, has reached you first. The message is encrypted, its code a swirling anomaly of characters that defy logical patterns. It seems to mock your attempts at decryption with its bizarre complexity. What could it mean?


# Solutuon:
Given a link to a yt video where the variable talks with sigma boi playing in the bg, and a link to the song is put in the description, going over to the comments of the song, find the comment by the variable (can use https://www.hadzy.com/), it would ask the players to check out the variable's threads account. There u can find the ciphertext. The encoding is vigenere cipher with the key being the romanized original lyrics for sigma boi.


Now starting from copying the lyrics top to bottom and trying it as a key. The output is not attained. Now we start removing some of the additional lines that do not belong in the lyrics, not everything altogether, go one by one. 


Starting with `[Intro: Betsy & Maria Yankovskaya]`, following are the lyrics and u see quite some text being revealed, then we have `[Chorus: Betsy, Maria Yankovskaya, Both]` and `[Verse: Betsy & Maria Yankovskaya]`. These all a pretty straightforward, at this point you should have this:
![Screenshot 2025-02-04 231420](https://github.com/user-attachments/assets/022ad999-8d80-4adc-bc24-03115aecb020)


Now if u remove the `(Betsy, Betsy, Betsy, Betsy)`  u see some text getting encrypted again, this means its part of the key. Moving to other phrases ahead like `(Iu)(Aga)(Davay)` after being removed reveal more text.


Now we come to the part with a lot of useless text, for the first 2 lines its the same as Betsy Betsy line, removing them encrypts the text again, so they are also part of the key. Removing the upcoming lines one by one will reveal more text. Finally remove the last line in square brackets `[Chorus: Betsy & Maria Yankovskaya, Maria Yankovskaya, Betsy]`. Anddd u have the key. GG.


Flag: actf{4_tru3_s1gma_never_5top5_m0gg1ng}
