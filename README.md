<p><a href="https://hackaday.io/project/187948-hbsound">HBSound</a> is an attempt to make Hobbyist home brew sound card, based off a simple architecture that can be controlled from even a simple micro controller.</p>

<p><br>The design goals are:</p>


<ol><li>Based off mostly available parts ( TLC7528 8 bit DAC / 74HCT40105)</li><li>Requires only a hand full of minimal Motorola minimal controller signals to operate (E, R//W and A0)&nbsp; </li><li>No DMA, Halting the CPU, wait operation or Interrupts required (but optionally available).</li><li>HCT buffered control and data lines to allow for a broad rage of CPU's and controllers.</li></ol>


<p>This is mostly accomplished using the widely available CD74HCT40105 (a CMOS clone of the CD40105 14 word 4 bit FIFO) </p>


<p>The design can be adopted for any home brew computer but the card I will be building is based around the <a href="https://hackaday.io/project/186398-hb6809-homebrew-computer">HB6809 Home-brew expansion computer.<br></a></p>


<p><strong>First some caveats:&nbsp;
</strong></p>


<p>Every time I do a custom PCB design, I get feedback which I am very grateful for but here's a few things to&nbsp; keep in mind:
</p>


<ol><li><strong>Autodidact warning</strong> - I am self taught - this could be 100% wrong - but I did do testing on real hardware to determine its at least effectively working for my use-case.</li><li><strong>This is not a high speed design</strong> - it does not adhere to high speed design practices, it is meant to work at the maximum E value found in my computer which is 1.8432 MHz.&nbsp; <em>I should mention Howard W. Johnson / Martin Graham's book on high speed digital design (It is very good if you are in to that sort of thing)</em></li><li><strong>This is a hobby, I do it for fun -</strong>&nbsp; I don't plan to mass produce or sell any of these things that I build and so the build quality is not always going to be what you would expect from a commercially provided, professionally designed product.&nbsp; Furthermore, I don't expect that I am the best source of information on the "right way to do something" -- you absolutely should take everything here with that grain of salt.</li></ol>


<p><strong>Sponsorship: </strong><br></p>


<p>PCBWay Sponsored PCB assembly costs on this project during the prototyping phase, if you are interested in their highly recommended fabrication services please check them out.&nbsp; They offer PCB services, 3d prototyping and metal fabrication as well as PCB assembly services.&nbsp; Costs are reasonable and the quality even on their prototype boards is very good.&nbsp; Thank you <a href="https://pcbway.com/g/H86a7b">PCBWay!</a> without contributions like this it would be impossible to move projects along at this speed.</p>


<figure><a href="https://pcbway.com/g/H86a7b" target="_blank"><img style="width: 251px; height: 69px;" class="lazy" src="https://cdn.hackaday.io/images/881021673285829291.png" width="251" height="69"></a></figure>


<p><strong><br></strong><strong>License:</strong></p>


<p>HBSound is open hardware under : <a href="https://cern-ohl.web.cern.ch/">CERN-OH-P</a><br></p>
<H3> Libility / warranty language from the licence </h3>
<p>
5.1 DISCLAIMER OF WARRANTY -- The Covered Source and any Products
      are provided 'as is' and any express or implied warranties,
      including, but not limited to, implied warranties of
      merchantability, of satisfactory quality, non-infringement of
      third party rights, and fitness for a particular purpose or use
      are disclaimed in respect of any Source or Product to the
      maximum extent permitted by law. The Licensor makes no
      representation that any Source or Product does not or will not
      infringe any patent, copyright, trade secret or other
      proprietary right. The entire risk as to the use, quality, and
      performance of any Source or Product shall be with You and not
      the Licensor. This disclaimer of warranty is an essential part
      of this Licence and a condition for the grant of any rights
      granted under this Licence.

  5.2 EXCLUSION AND LIMITATION OF LIABILITY -- The Licensor shall, to
      the maximum extent permitted by law, have no liability for
      direct, indirect, special, incidental, consequential, exemplary,
      punitive or other damages of any character including, without
      limitation, procurement of substitute goods or services, loss of
      use, data or profits, or business interruption, however caused
      and on any theory of contract, warranty, tort (including
      negligence), product liability or otherwise, arising in any way
      in relation to the Covered Source, modified Covered Source
      and/or the Making or Conveyance of a Product, even if advised of
      the possibility of such damages, and You shall hold the
      Licensor(s) free and harmless from any liability, costs,
      damages, fees and expenses, including claims by third parties,
      in relation to such use.
</p>
