#class {stdio.h} {kill}
#class {stdio.h} {open}


#var vmsg {0}


#alias verbose.level {

	#if {%1 == 1 || %1 == 2 || %1 == 3} {

	     #var vmsg {%1};
	     #showme {Verbose level set: %1}

	};#else {
		#bell;
		#showme {-- Usage: verbose.level <level (1-3)> }
	}

}


#function test_fprintf {
		
	#showme {-- Verbosity level: $vmsg};

	@fprintf{1;This is a level 1 message};
	@fprintf{2;This is a level 2 message};
	@fprintf{3;This is a level 3 message};
	
}


#function fprintf {
	
	#switch {$vmsg} {
		#case {1} {
			
			#if {%1 == 1} {
				#showme {%2}
			};

			#return
		}; 
		#case {2} {

                        #if {%1 == 1 || %1 == 2} {
                                #showme {%2}
                        };
			
			#return
                };
		#case {3} {

                        #if {%1 == 1 || %1 == 2 || %1 == 3} {
                                #showme {%2}
                        };

                        #return
                };
		#default {
			#return
		} 
	}

	#return
}

#class {stdio.h} {close}