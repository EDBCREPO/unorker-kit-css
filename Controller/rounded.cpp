#pragma once

namespace uk { 

    express_tcp_t rounded() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send();

            for( auto& item : map_t<string_t,string_t>({
                { "none",    "0px"  },
                { "2xsmall", "2px"  },
                { "xsmall",  "5px"  },
                { "small",   "10px" },
                { "medium",  "20px" },
                { "large",   "25px" },
                { "xlarge",  "30px" },
                { "2xlarge", "35px" }
            }).data() ){
                cli.write( regex::format( _STRING_(
                   .uk-rounded-hover-${0}:hover { border-radius: ${1}; }
                   .uk-rounded-${0}             { border-radius: ${1}; }
                ), item.first, item.second ));
            }

            cli.write( _STRING_ ( 
                
                .uk-rounded-remove-top { 
                    border-top-left-radius:  0px; 
                    border-top-right-radius: 0px; 
                }
                
                .uk-rounded-remove-left { 
                    border-top-left-radius:    0px; 
                    border-bottom-left-radius: 0px; 
                }
                
                .uk-rounded-remove-right { 
                    border-top-right-radius:    0px; 
                    border-bottom-right-radius: 0px; 
                }
                
                .uk-rounded-remove-bottom { 
                    border-bottom-left-radius:  0px; 
                    border-bottom-right-radius: 0px; 
                }
                
                .uk-rounded-remove { 
                    border-top-left-radius:     0px; 
                    border-top-right-radius:    0px; 
                    border-bottom-left-radius:  0px; 
                    border-bottom-right-radius: 0px; 
                }

                .uk-rounded-hover:hover { border-radius: 15px; } 
                .uk-rounded             { border-radius: 15px; } 
                
            ));

        });

        return app;
    }

}