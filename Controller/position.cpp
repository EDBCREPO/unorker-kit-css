#pragma once

namespace uk { 

    express_tcp_t position() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send();
                
            cli.write( _STRING_( [class*=uk-position]{ position: absolute; }));

            for( auto& size: map_t<string_t,int>({ 
                { nullptr,   0 },
                { "\\@s",  640 },
                { "\\@m",  960 },
                { "\\@l", 1200 },
                { "\\@2l",1600 }
            }).data() ){

                if( size.first != nullptr ){
                    cli.write( regex::format( _STRING_(
                       @media( min-width: ${0}px ) {
                    ), size.second ));
                }

                for( auto& item : map_t<string_t,string_t>({
                    { "center",       "bottom: 0; left: 0; right: 0; top: 0;" },
                    { "bottom",       "bottom: 0; left: 0; right: 0;"         },
                    { "right",        "bottom: 0; top: 0; right: 0;"          },
                    { "left",         "bottom: 0; top: 0; left: 0;"           },
                    { "top",          "top: 0; left: 0; right: 0;"            },
                    { "top-left",     "top: 0; left: 0;"                      },
                    { "top-right",    "top: 0; right: 0;"                     },
                    { "bottom-left",  "bottom: 0; left: 0;"                   },
                    { "bottom-right", "bottom: 0; right: 0;"                  },
                }).data() ){
                    cli.write( regex::format( _STRING_(
                       .uk-position-${0}${2} { ${1} }
                    ), item.first, item.second, size.first ));
                }

                for( auto& item : ptr_t<string_t>({
                    "absolute", "fixed", "sticky", "relative"
                }) ){
                    cli.write( regex::format( _STRING_(
                       .uk-position-${0}${1} { position: ${0} !important; }
                    ), item, size.first ));
                }

                if( size.first != nullptr ){ cli.write( "}" ); }

            }

        });

        return app;
    }

}