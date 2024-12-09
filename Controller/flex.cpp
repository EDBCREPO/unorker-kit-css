#pragma once

namespace uk { 

    express_tcp_t flex() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send();

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

                cli.write( regex::format( _STRING_(
                    .uk-flex-inline${0}  { display: inline-flex; }
                    .uk-flex-initial${0} { flex: initial; }
                    .uk-flex-none${0}    { flex: none; }
                    .uk-flex-auto${0}    { flex: auto; }
                    .uk-flex${0}         { display: flex; }
                ), size.first ));

                for( auto& item: map_t<string_t,string_t>({
                    { "around",  "space-around"  },
                    { "between", "space-between" },
                    { "center",  "center"        },
                    { "left",    "flex-start"    },
                    { "right",   "flex-end"      }
                }).data() ){
                    cli.write( regex::format( _STRING_(
                       .uk-flex-${0}${2} { justify-content: ${1}; }
                    ), item.first, item.second, size.first )); 
                }

                for( auto& item: map_t<string_t,string_t>({
                    { "top",     "flex-start" },
                    { "bottom",  "flex-end"   },
                    { "stretch", "stretch"    },
                    { "middle",  "center"     },
                }).data() ){
                    cli.write( regex::format( _STRING_(
                       .uk-flex-${0}${2} { align-items: ${1}; }
                    ), item.first, item.second, size.first )); 
                }

                for( auto& item: ptr_t<string_t>({
                    "column-reverse", "column",
                    "row", "row-reverse"
                })){
                    cli.write( regex::format( _STRING_(
                       .uk-flex-${0}${1} { flex-direction: ${0}; }
                    ), item, size.first )); 
                }

                for( auto& item: ptr_t<string_t>({
                    "wrap", "nowrap", "wrap-reverse"
                })){
                    cli.write( regex::format( _STRING_(
                       .uk-flex-${0}${1} { flex-wrap: ${0}; }
                    ), item, size.first )); 
                }

                for( auto& item: map_t<string_t,string_t>({
                    { "between", "space-between" },
                    { "around",  "space-around"  },
                    { "top",     "flex-start"    },
                    { "bottom",  "flex-end"      },
                    { "stretch", "stretch"       },
                    { "middle",  "center"        },
                }).data() ){
                    cli.write( regex::format( _STRING_(
                       .uk-flex-wrap-${0}${2} { align-content: ${1}; }
                    ), item.first, item.second, size.first )); 
                }

                if( size.first != nullptr ){ cli.write( "}" ); }
            
            }

        });

        return app;
    }

}